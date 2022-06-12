FROM gcc:4.9
COPY . .
WORKDIR /stress_cpu/
RUN gcc -o stress_cpu -std=c99 -O0 stress_cpu.c
CMD ["./stress_cpu"]
