from flask import Flask, request, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app)  # Enables CORS for all domains on all routes

@app.route("/", methods=["POST"])
def get_input():
    contents = request.json.get("contents")
    print(contents)
    # You can now process 'contents' as needed
    return jsonify({"status": "Received", "contents": contents})

if __name__ == "__main__":
    app.run(debug=True)
