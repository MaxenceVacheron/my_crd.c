FROM gcc:4.9
# COPY . /usr/src/myapp
WORKDIR /var/www/html/

RUN mkdir libmy
RUN mkdir Release

COPY ./Makefile /var/www/html/
COPY ./libmy/ /var/www/html/libmy/
COPY ./Release/ /var/www/html/Release

# WORKDIR /usr/src/myapp
RUN make
# CMD ["./Release/my_crd"]
