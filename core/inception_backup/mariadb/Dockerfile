FROM debian:11
RUN apt-get -y update && apt-get install -y mariadb-server
RUN mkdir -p /run/mariadb/mysqld
RUN chown -R mysql:root /run/mariadb/mysqld
LABEL version="1.0"
LABEL description="MariaDB Server"
HEALTHCHECK --start-period=5m \
  CMD mariadb -e 'SELECT @@datadir;' || exit 1

CMD ["mariadbd"]
