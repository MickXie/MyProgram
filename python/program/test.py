
import sys
import os
script_path = os.path.abspath(__file__)
absolute_path = os.path.join(os.path.dirname(script_path), )
absolutes_path = os.path.dirname(absolute_path)
print(absolutes_path)
sys.path.append(absolutes_path)
print(sys.path)
