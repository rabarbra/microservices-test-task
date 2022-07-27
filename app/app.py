from os import getenv
from flask import Flask
from werkzeug.routing.rules import Rule

app = Flask(__name__)
app.url_map.add(Rule('/', defaults={'path': ''}, endpoint='index'))
app.url_map.add(Rule('/<path:path>', endpoint='index'))

@app.endpoint('index')
def index(path: str):
    return f"Hello, {getenv('GREETING_NAME', '')}"
