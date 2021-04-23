if [ "$1" == "init" ]; then 
	service mysql start
	chown -R www-data /var/www/*
	chmod -R 755 /var/www/*
	mkdir /var/www/ninja_flex && touch /var/www/ninja_flex/index_giordi.php
	echo "<?php echo 'Giordano 107<br>'; phpinfo(); ?>" >> /var/www/ninja_flex/index_giordi.php
	mkdir /etc/nginx/ssl
	openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/ninja_flex.pem -keyout /etc/nginx/ssl/ninja_flex.key -subj "/C=IT/ST=Italy/L=Roma/O=42Roma/OU=dlanotte/CN=ninja_flex"
	ln -s /etc/nginx/sites-available/ninja_flex /etc/nginx/sites-enabled/ninja_flex
	rm -rf /etc/nginx/sites-enabled/default
	echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
	echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
	echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
	echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password
	mkdir /var/www/ninja_flex/phpmyadmin
	wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz
	tar -xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz --strip-components 1 -C /var/www/ninja_flex/phpmyadmin
	mv ./tmp/phpmyadmin.inc.php /var/www/ninja_flex/phpmyadmin/config.inc.php
	cd /tmp/
	wget -c https://wordpress.org/latest.tar.gz
	tar -xvzf latest.tar.gz
	mv wordpress/ /var/www/ninja_flex
	mv /tmp/wp-config.php /var/www/ninja_flex/wordpress
fi

if [ "$1" == "autoindex" ] || [ "$1" == "init" ]; then 
	if [ "$2" == "ON" ]; then 
		cp /tmp/nginx-conf_on /etc/nginx/sites-available/nginx-conf_on
	elif [ "$2" == "OFF" ]; then 
		cp /tmp/nginx-conf_off /etc/nginx/sites-available/nginx-conf_off
	fi
	mv /etc/nginx/sites-available/nginx-conf_* /etc/nginx/sites-available/ninja_flex
	service nginx restart
fi

if [ "$1" == "init" ]; then 
	#start service
	service php7.3-fpm start
	service nginx start
	bash
fi
