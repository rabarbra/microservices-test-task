FROM python:alpine

WORKDIR /app
ENV FLASK_APP=app

COPY app/requirements.txt app/app.py ./
RUN pip3 install -r requirements.txt

CMD [ "python3", "-m" , "flask", "run", "--host=0.0.0.0", "--port", "8080"]