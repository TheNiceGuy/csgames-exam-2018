FROM base/archlinux:latest

RUN pacman -Syu --noconfirm \
        python-flask \
        python-selenium \
        python-requests \
        geckodriver \
        firefox

WORKDIR "/client"
COPY "client.py" .

ENTRYPOINT ["python"]
CMD ["client.py"]
