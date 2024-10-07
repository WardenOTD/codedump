FROM debian:11
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y mariadb-server

COPY ./conf/mdb-conf.sh /mdb-conf.sh
RUN chmod +x /mdb-conf.sh

EXPOSE 3306
ENTRYPOINT ["./mdb-conf.sh"]

# LABEL version="1.0"
# LABEL description="MariaDB Server"
# HEALTHCHECK --start-period=5m \
#  CMD mariadb -e 'SELECT @@datadir;' || exit 1

# CMD ["mariadbd"]
