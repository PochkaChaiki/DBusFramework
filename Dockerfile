# Dockerfile
FROM ubuntu:22.04

# Установка зависимостей
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    qt6-base-dev \
    libqt6dbus6 \
    dbus-x11

# Копирование и сборка проекта

WORKDIR /app

COPY . .

RUN cmake . && make

# Запуск приложения
# CMD ["dbus-launch --auto-syntax"]


# CMD ["dbus-monitor"]

CMD ["eval", "`dbus-launch --auto-syntax`"]

CMD ["./dbusframework"]

