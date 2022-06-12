FROM gcc:4.9
COPY . .
WORKDIR /stress_cpu_inf/
RUN gcc -o stress_cpu_inf -std=c99 -O0 stress_cpu_inf.c
CMD ["./stress_cpu_inf"]
