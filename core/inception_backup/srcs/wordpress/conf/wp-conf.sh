#!/bin/bash

# wp cli stuff
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

# wp permissions stuff
mkdir /var/www/wordpress
cd /var/www/wordpress
chmod -R 755 /var/www/wordpress/
chown -R www-data:www-data /var/www/wordpress

# check mariadb running
ping_mariadb_container() {
    nc -zv mariadb 3306 > /dev/null # ping mariadb
    return $? # return exit status of ping
}

start_time=$(date +%s) # current time in seconds
end_time=$((start_time + 20)) # set end time to 20 seconds after start
while [ $(date +%s) -lt $end_time ]; do # loop while current_time < end_time
    ping_mariadb_container # ping mariadb
    if [ $? -eq 0 ]; then # check if successful
        echo "[========MARIADB IS UP AND RUNNING========]"
        break
    else
        echo "[========WAITING FOR MARIADB TO START...========]"
        sleep 1 # wait 1 second to prevent spam
    fi
done

if [ $(date +%s) -ge $end_time ]; then # check if current_time > end_time
    echo "[========MARIADB IS NOT RESPONDING========]"
fi

# wp core files stuff
wp core download --allow-root
# # create default wp config file
# wp config create --dbhost=mariadb:3306 --dbname="${MYSQL_DB}" --dbuser="${MYSQL_USER}" --dbpass="${MYSQL_PASSWORD}" --allow-root
# create wp-config.php file with database details
wp core config --dbhost=mariadb:3306 --dbname="${MYSQL_DB}" --dbuser="${MYSQL_USER}" --dbpass="${MYSQL_PASSWORD}" --allow-root
# install wp
wp core install --url="${DOMAIN_NAME}" --title="${WP_TITLE}" --admin_user="${WP_ADMIN_N}" --admin_password="${WP_ADMIN_P}" --admin_email="${WP_ADMIN_E}" --allow-root
#create new user
wp user create "${WP_U_NAME}" "${WP_U_EMAIL}" --user_pass="${WP_U_PASS}" --role="${WP_U_ROLE}" --allow-root


# change listen port from unix socket to 9000
sed -i '36 s@/run/php/php7.4-fpm.sock@9000@' /etc/php/7.4/fpm/pool.d/www.conf
# create directory for php-fpm
mkdir -p /run/php
# start php-fpm service in the foreground to keep the container running
/usr/sbin/php-fpm7.4 -F
