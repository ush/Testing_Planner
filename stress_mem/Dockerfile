FROM gcc:4.9
COPY . .
WORKDIR /stress_mem/
RUN gcc -o stress_mem -std=c99 -O0 stress_mem.c
CMD ["./stress_mem"]
