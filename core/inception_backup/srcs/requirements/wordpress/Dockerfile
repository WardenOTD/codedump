FROM debian:11
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y curl php php7.4-fpm php-mysql mariadb-client netcat

COPY ./conf/wp-conf.sh /wp-conf.sh
RUN chmod +x wp-conf.sh

ENTRYPOINT ["./wp-conf.sh"]

# RUN mkdir -p /var/www/
# RUN cd /var/www
# RUN apt-get -y update && apt-get -y install wget
# RUN wget https://wordpress.org/latest.tar.gz
# RUN tar -xzvf latest.tar.gz
# RUN rm latest.tar.gz
# RUN chown -R www-data:www-data wordpress
# RUN find wordpress/ -type d -exec chmod 777 {} \;
# RUN find wordpress/ -type f -exec chmod 777 {} \;
