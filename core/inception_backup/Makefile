build:
		docker compose -f ./docker_compose.yml build
		docker compose -f ./docker_compose.yml up

stop:
		docker compose -f ./docker_compose.yml down

fclean:
		docker system prune -af
		docker volume prune -af
		docker image prune -af

re: fclean
		make build
