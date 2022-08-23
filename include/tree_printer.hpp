// Copy from https://github.com/Jinyu-Qin/TreePrinter
#ifndef __TREE_PRINTER_H__
#define __TREE_PRINTER_H__

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <climits>

using namespace std;

namespace tp
{

  const string version = "V1.0.0";

  template <typename TreeNode>
  class SimpleTreeNodeAdapter
  {
  public:
    using origin_type = TreeNode;
    using node_type = SimpleTreeNodeAdapter;

    SimpleTreeNodeAdapter(origin_type *root)
        : root_(root), left_(root->left == nullptr ? nullptr : new node_type(root->left)), right_(root->right == nullptr ? nullptr : new node_type(root->right)) {}

    ~SimpleTreeNodeAdapter()
    {
      if (left_ != nullptr)
      {
        delete left_;
        left_ = nullptr;
      }

      if (right_ != nullptr)
      {
        delete right_;
        right_ = nullptr;
      }
    }

    string content()
    {
      return to_string(root_->val);
    }

    node_type *left()
    {
      return left_;
    }

    node_type *right()
    {
      return right_;
    }

  private:
    origin_type *root_;
    node_type *left_;
    node_type *right_;
  };

  template <typename TreeNode>
  class SimpleRbTreeNodeAdapter
  {
  public:
    using origin_type = TreeNode;
    using node_type = SimpleRbTreeNodeAdapter;

    SimpleRbTreeNodeAdapter(origin_type *root)
        : root_(root), left_(root->left == nullptr ? nullptr : new node_type(root->left)), right_(root->right == nullptr ? nullptr : new node_type(root->right)) {}

    ~SimpleRbTreeNodeAdapter()
    {
      if (left_ != nullptr)
      {
        delete left_;
        left_ = nullptr;
      }

      if (right_ != nullptr)
      {
        delete right_;
        right_ = nullptr;
      }
    }

    string content()
    {
      return to_string(root_->val) + (root_->color == 0 ? "[B]" : "[R]");
    }

    node_type *left()
    {
      return left_;
    }

    node_type *right()
    {
      return right_;
    }

  private:
    origin_type *root_;
    node_type *left_;
    node_type *right_;
  };

  template <typename TreeNode, typename TreeNodeAdapter = SimpleTreeNodeAdapter<TreeNode>>
  class TreePrinter
  {
  public:
    using origin_type = typename TreeNodeAdapter::origin_type;
    using node_type = typename TreeNodeAdapter::node_type;

    TreePrinter(origin_type *root)
        : root_(new node_type(root))
    {
      init();
    }

    ~TreePrinter()
    {
      if (root_ != nullptr)
      {
        delete root_;
        root_ = nullptr;
      }
    }

    void print() const
    {
      printBuf();
    }

  private:
    class Cell
    {
    public:
      enum status_type
      {
        None,
        LeftLine,
        RightLine,
        Line
      };

      Cell(int row, int col, int width, int height, vector<vector<char>> &buf, node_type *node = nullptr, status_type status = None)
          : node_(node), status_(status), row_(row), col_(col), buf_(&buf), width_(width), height_(height) {}

      void position(int row, int col)
      {
        row_ = row;
        col_ = col;
      }

      pair<int, int> position() const
      {
        return {row_, col_};
      }

      void node(node_type *node)
      {
        node_ = node;
      }

      node_type *node() const
      {
        return node_;
      }

      void status(status_type status)
      {
        status_ = status;
      }

      status_type status() const
      {
        return status_;
      }

      void fill()
      {
        const int x0 = col_ * width_;
        const int y0 = row_ * height_;
        auto &buf = *buf_;

        int x = x0;
        int y = y0;
        int cnt = 0;

        if (node_ == nullptr)
        {
          switch (status_)
          {
          case None:
            break;

          case LeftLine:
            x = x0;
            y = y0 + height_ - 1;
            cnt = width_ / 2;

            for (int i = 0; i < cnt; ++i)
            {
              buf[y][x++] = '-';
            }
            buf[y][x] = '\\';
            break;

          case RightLine:
            x = x0 + width_ / 2;
            y = y0 + height_ - 1;
            cnt = width_ - width_ / 2 - 1;

            buf[y][x++] = '/';
            for (int i = 0; i < cnt; ++i)
            {
              buf[y][x++] = '-';
            }
            break;

          case Line:
            x = x0;
            y = y0 + height_ - 1;
            cnt = width_;

            for (int i = 0; i < cnt; ++i)
            {
              buf[y][x++] = '-';
            }
            break;
          }
        }
        else
        {
          const string &content = node_->content();
          int rightSpaceCnt = (width_ - content.size()) / 2;
          int leftSpaceCnt = width_ - content.size() - rightSpaceCnt;

          x = x0 + width_ / 2;
          y = y0;

          buf[y][x] = '|';

          x = x0;
          y = y0 + height_ - 1;

          for (int i = 0; i < leftSpaceCnt; ++i)
          {
            buf[y][x++] = node_->left() == nullptr ? ' ' : '-';
          }
          for (const char c : content)
          {
            buf[y][x++] = c;
          }
          for (int i = 0; i < rightSpaceCnt; ++i)
          {
            buf[y][x++] = node_->right() == nullptr ? ' ' : '-';
          }
        }
      }

      void clear()
      {
        const int x0 = col_ * width_;
        const int y0 = row_ * height_;
        auto &buf = *buf_;

        int x = x0;
        int y = y0;
        for (int i = 0; i < height_; ++i)
        {
          for (int j = 0; j < width_; ++j)
          {
            buf[y][x++] = ' ';
          }
          ++y;
          x = x0;
        }
      }

    private:
      node_type *node_;
      status_type status_;
      int row_;
      int col_;
      vector<vector<char>> *buf_;
      int width_;
      int height_;
    };

    void init()
    {
      computePosition(root_, 0, 0);
      computeCellParams();
      initBuf();
      initCells();
    }

    void computePosition(node_type *root, int row, int col)
    {
      if (root == nullptr)
      {
        return;
      }

      colMap_[root] = col;
      rowMap_[root] = row;

      int offset = 1;
      do
      {
        int leftCol = col - offset;
        int rightCol = col + offset;

        computePosition(root->left(), row + 1, leftCol);
        computePosition(root->right(), row + 1, rightCol);

        ++offset;
      } while (overlay(root->left(), root->right()));
    }

    void computeCellParams()
    {
      colMin_ = INT_MAX;
      colMax_ = INT_MIN;
      int contentLenMax = INT_MIN;
      int depthMax = INT_MIN;

      for (auto &p : colMap_)
      {
        node_type *node = p.first;
        int col = p.second;

        colMin_ = min(colMin_, col);
        colMax_ = max(colMax_, col);
        contentLenMax = max(contentLenMax, static_cast<int>(node->content().size()));
        depthMax = max(depthMax, rowMap_[node]);
      }

      colOffset_ = -colMin_;
      cellCols_ = colMax_ - colMin_ + 1;
      cellRows_ = depthMax + 1;
      cellWidth_ = contentLenMax + 2;
      cellHeight_ = 2;
    }

    void initBuf()
    {
      const int bufCols = cellCols_ * cellWidth_;
      const int bufRows = cellRows_ * cellHeight_;
      buf_.assign(bufRows, vector<char>(bufCols));
    }

    void initCells()
    {
      cells_.assign(cellRows_, vector<Cell>(cellCols_, Cell(0, 0, cellWidth_, cellHeight_, buf_)));
      for (int row = 0; row < cellRows_; ++row)
      {
        for (int col = 0; col < cellCols_; ++col)
        {
          Cell &cell = cells_[row][col];
          cell.position(row, col);
          cell.clear();
        }
      }

      for (auto &p : colMap_)
      {
        node_type *node = p.first;
        int col = p.second + colOffset_;
        int row = rowMap_[node];

        Cell &cell = cells_[row][col];
        cell.node(node);
        cell.fill();
      }

      for (auto &p : colMap_)
      {
        node_type *node = p.first;
        int col = p.second + colOffset_;
        int row = rowMap_[node];

        if (node->left() != nullptr)
        {
          int r = row + 1;
          for (int c = col - 1; c >= 0; --c)
          {
            Cell &cell = cells_[row][c];
            Cell &bottom = cells_[r][c];

            if (bottom.node() == nullptr)
            {
              cell.status(Cell::Line);
              cell.fill();
            }
            else
            {
              cell.status(Cell::RightLine);
              cell.fill();
              break;
            }
          }
        }

        if (node->right() != nullptr)
        {
          int r = row + 1;
          for (int c = col + 1; c < cellCols_; ++c)
          {
            Cell &cell = cells_[row][c];
            Cell &bottom = cells_[r][c];

            if (bottom.node() == nullptr)
            {
              cell.status(Cell::Line);
              cell.fill();
            }
            else
            {
              cell.status(Cell::LeftLine);
              cell.fill();
              break;
            }
          }
        }
      }
    }

    void printBuf() const
    {
      for (auto &line : buf_)
      {
        for (auto c : line)
        {
          cout << c;
        }
        cout << endl;
      }
    }

    bool overlay(node_type *left, node_type *right)
    {
      if (left == nullptr || right == nullptr)
      {
        return false;
      }

      int p = colMap_[left];
      int q = colMap_[right];

      if (!(p < q))
      {
        return true;
      }

      return overlay(left->right(), right) || overlay(left, right->left()) || overlay(left->right(), right->left());
    }

    node_type *root_;

    unordered_map<node_type *, int> colMap_;
    unordered_map<node_type *, int> rowMap_;

    int colMin_;
    int colMax_;
    int colOffset_;

    vector<vector<char>> buf_;
    vector<vector<Cell>> cells_;
    int cellCols_;
    int cellRows_;
    int cellWidth_;
    int cellHeight_;
  };

}

#endif //__TREE_PRINTER_H__
