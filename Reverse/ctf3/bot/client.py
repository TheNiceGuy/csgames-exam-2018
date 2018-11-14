import base64
import json
import time
import os
import requests

from selenium import webdriver

# get the website
if "VULNERABLE_WEBSITE" in os.environ:
    website = os.environ["VULNERABLE_WEBSITE"]
else:
    website = "http://127.0.0.1/"

# get the route
if "VULNERABLE_ROUTE" in os.environ:
    route = os.environ["VULNERABLE_ROUTE"]
else:
    route = ""

# compute the address to visit
address = website + route

# get the cookie key
if "COOKIE_KEY" in os.environ:
    cookie_key = os.environ["COOKIE_KEY"]
else:
    cookie_key = "SESSION_KEY"

# get the session
if "SESSION_ID" not in os.environ:
    print("Missing `SESSION_ID` environment variable.")
    exit(1)
session = os.environ["SESSION_ID"]

# get our public IP address
data = requests.get("http://wtfismyip.com/json").json()
ip = data["YourFuckingIPAddress"]

# create the cookie
cookie_value = session + ":" + ip
cookie_value = base64.b64encode(cookie_value.encode("utf-8")).decode("utf-8")
print("IP address: {}".format(ip))

# give some time for the website to start
time.sleep(10)

# create a browser
options = webdriver.firefox.options.Options()
options.headless = True
browser = webdriver.Firefox(options=options)

# visit the website
print("Website: {}".format(address))
browser.get(address)

while True:
    # add the cookie
    print("Cookie: {}={}".format(cookie_key, cookie_value))
    browser.add_cookie({"name": cookie_key, "value": cookie_value})

    # refresh page
    browser.refresh()
    print(browser.page_source)

    # wait some time
    time.sleep(10)


