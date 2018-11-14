from flask import Flask, request

# application
app = Flask(__name__)

# last values for each path
data = dict()

@app.route('/post/',            methods=['GET'], defaults={'path': ''})
@app.route('/post/<path:path>', methods=['GET'])
def post_data(path):
    # save the value for the path
    if "DATA" in request.args:
        data[path] = request.args["DATA"]
        return ""
    if "DATA" in request.form:
        data[path] = request.form["DATA"]
    return ""

@app.route('/get/',            methods=['GET'], defaults={'path': ''})
@app.route('/get/<path:path>', methods=['GET'])
def get_data(path):
    # return the value if possible
    if path in data:
        return data[path]
    return "Nothing"

if __name__ == '__main__':
    app.run(debug=False, host='0.0.0.0')
