import subprocess
import sys

if len(sys.argv) < 3:
    print("Usage: python save_ansi_output.py <command> <output_file>")
    sys.exit(1)

command = sys.argv[1]
output_file = sys.argv[2]

with open(output_file, 'w', encoding='utf-8') as f:
    result = subprocess.run(command, shell=True, text=True, encoding='utf-8', stderr=subprocess.PIPE, stdout=subprocess.PIPE)
    f.write(result.stdout)
    f.write(result.stderr)

print(f"Command output saved to {output_file}")