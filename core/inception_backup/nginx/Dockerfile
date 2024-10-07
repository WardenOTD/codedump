FROM debian:11
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y nginx
RUN apt-get install -y openssl

RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout \
    /etc/nginx/ssl/inception.key -subj "/C=MY/ST=Selangor/L=Subang Jaya/O=42KL/OU=Cadet/CN=jteoh.42.fr/UID=super"

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
RUN mkdir -p /var/www/wordpress
RUN chown -R www-data:www-data /var/www/wordpress

EXPOSE 443
CMD ["nginx", "-g", "daemon off;"]
