FROM python:3-slim

RUN pip install flask flask_cors

WORKDIR "/server"
COPY "server.py" .

EXPOSE 5000

ENTRYPOINT ["python"]
CMD ["server.py"]
