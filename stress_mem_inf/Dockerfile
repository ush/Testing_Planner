FROM gcc:4.9
COPY . .
WORKDIR /stress_mem_inf/
RUN gcc -o stress_mem_inf -std=c99 -O0 stress_mem_inf.c
CMD ["./stress_mem_inf"]
