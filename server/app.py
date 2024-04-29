from flask import Flask, request, CORS

app = Flask(__name__)

@app.route("/",methods="POST")
def GetInput():
    contents = request.json["contents"]

if __name__ == "__main__":
    app.run(debug=True)