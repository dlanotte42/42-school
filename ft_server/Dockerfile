# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/13 15:29:40 by dlanotte          #+#    #+#              #
#    Updated: 2021/02/17 19:37:17 by dlanotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update && apt-get install -y procps 
RUN apt-get install nano && apt-get install -y wget  
RUN apt-get -y install php7.3-fpm php7.3-common php7.3-mysql php7.3-gmp php7.3-curl php7.3-intl php7.3-mbstring php7.3-xmlrpc php7.3-gd php7.3-xml php7.3-cli php7.3-zip php7.3-soap php7.3-imap && apt-get -y install wget && apt-get -y install nginx && apt-get -y install mariadb-server
COPY ./srcs/install_all.sh ./
COPY ./srcs/nginx-conf_on ./tmp/nginx-conf_on
COPY ./srcs/nginx-conf_off ./tmp/nginx-conf_off
COPY ./srcs/phpmyadmin.inc.php ./tmp/phpmyadmin.inc.php
COPY ./srcs/wp-config.php ./tmp/wp-config.php

RUN chmod 755 /install_all.sh
CMD bash ./install_all.sh init ON