FROM debian:11
RUN  apt-get -y update && apt-get -y install nginx
COPY conf/default /etc/nginx/sites-available/default
COPY conf/index.html 42/Inception/nginx/files
EXPOSE 80
CMD ["/usr/sbin/nginx", "-g", "daemon off;"]
