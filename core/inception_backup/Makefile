WP_DATA = /home/data/wordpress
MDB_DATA = /home/data/mariadb

all: up

up: build
		mkdir -p $(WP_DATA)
		mkdir -p $(MDB_DATA)
		docker compose -f ./docker_compose.yml up -d

down:
		docker compose -f ./docker_compose.yml down

start:
		docker compose -f ./docker_compose.yml start

stop:
		docker compose -f ./docker_compose.yml stop

build:
		docker compose -f ./docker_compose.yml build

fclean:
		docker stop $$(docker ps -qa) || true
		docker rm $$(docker ps -qa) || true
		docker rmi -f $$(docker images -qa) || true
		docker volume rm $$(docker volume ls -q) || true
		docker network rm $$(docker network ls -q) || true
		rm -rf $(WP_DATA) || true
		rm -rf $(MDB_DATA) || true

prune: fclean
		docker system prune -a --volumes -f

re: fclean up
