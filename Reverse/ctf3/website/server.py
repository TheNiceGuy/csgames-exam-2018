import os
import base64

from flask import Flask
from flask import request, redirect, url_for, render_template, make_response, flash

app = Flask(__name__)

# get the secret key
if "SECRET_KEY" in os.environ:
    app.secret_key = os.environ["SECRET_KEY"]
else:
    app.secret_key = "r2OFVwIco+QIFDH5WFTlxct7Ll1X7o23"

# get the secret route
if "SECRET_ROUTE" in os.environ:
    secret_route = "/" + os.environ["SECRET_ROUTE"]
else:
    secret_route = "/GPrVekmClPYUrrSy"

# get the cookie key
if "COOKIE_KEY" in os.environ:
    cookie_key = os.environ["COOKIE_KEY"]
else:
    cookie_key = "SESSION_KEY"

# get the session
if "SESSION_ID" not in os.environ:
    print("Missing `SESSION_ID` environment variable.")
    exit(1)
session_id = os.environ["SESSION_ID"]

# get the flag
if "FLAG" not in os.environ:
    print("Missing `FLAG` environment variable.")
    exit(1)
flag = os.environ["FLAG"]

# the requests made by the user
request_queue = list()

class AccessRequest(object):
    def __init__(self, fname, lname, matricule, program, introduction):
        self.__fname = fname
        self.__lname = lname
        self.__matricule = matricule
        self.__program = program
        self.__introduction = introduction

    def __str__(self):
        return "{} {} {} {} {}".format(
            self.__fname,
            self.__lname,
            self.__matricule,
            self.__program,
            self.__introduction
        )

    @staticmethod
    def from_dict(values):
        return AccessRequest(
            values["fname"],
            values["lname"],
            values["matricule"],
            values["program"],
            values["introduction"]
        )

def check_session():
    # decode the cookie
    try:
        key = base64.b64decode(request.cookies[cookie_key]).decode("utf-8")
    except:
        return False

    # make sure the session ID is valid
    session = key.split(':')[0]
    if session != session_id:
        flash(u"ملف تعريف ارتباط غير صالح", "error")
        return False
        
    # make sure the IP matches the request
    address = key.split(':')[1]
    if address != request.remote_addr:
        flash(u"كعكة فاسدة", "error")
        return False

    return True

@app.route("/")
def index():
    # check if the cookie is valid
    if check_session():
        return render_template("index.html", flag=flag)

    # redirect to login page if it isn't
    return redirect(url_for("login"))

@app.route("/request", methods=["GET", "POST"])
def register():
    # redirect if cookie is valid
    if check_session():
        return redirect(url_for("index"))

    # return the web page for GET
    if request.method == "GET":
        return render_template("request.html")

    # create a request for POST
    try:
        access_request = AccessRequest.from_dict(request.form)
        request_queue.append(access_request)
        flash(u"تم ارسال طلبك", "status")
    except Exception as e:
        flash(u"حدث خطأ داخلي", "error")
    return redirect(url_for("login"))

@app.route("/login", methods=["GET", "POST"])
def login():
    # redirect if cookie is valid
    if check_session():
        return redirect(url_for("index"))

    # login always fails
    if request.method == "POST":
        flash(u"المصادقة فشلت", "error")
    return render_template("login.html")

@app.route(secret_route)
def handle_request():
    # get the next request
    if len(request_queue) == 0:
        return "No more request"

    # show the request
    response = make_response(request_queue.pop(0).__str__())
    response.headers["Access-Control-Allow-Origin"] = "*"
    return response

if __name__ == '__main__':
    app.run(debug=False, host='0.0.0.0')
    
