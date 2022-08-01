FROM gcc AS builder
WORKDIR /app
COPY app/app.c ./
RUN gcc -o my_app app.c

FROM alpine:latest
WORKDIR /app
COPY --from=builder /app/my_app ./
RUN apk add libc6-compat
CMD ["./my_app"]
EXPOSE 8080