from flask import Flask, request, jsonify
from flask_cors import CORS
from ctypes import cdll
import subprocess

app = Flask(__name__)
CORS(app)

@app.route("/", methods=["POST"])
def get_input():
    contents = request.json.get("contents")
    with open('received_contents.txt', 'w') as file:
        file.write(contents + "\n")
    result = subprocess.run(['./start.exe'], capture_output=True, text=True)
    depth = result.stdout.strip()
    return jsonify({"status": "Received", "contents": contents, "depth":depth})

if __name__ == "__main__":
    app.run(debug=True,port=5000)
