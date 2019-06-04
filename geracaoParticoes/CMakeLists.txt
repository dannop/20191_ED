cmake_minimum_required(VERSION 3.10)
project(geracao_particoes)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(geracao_particoes
        cliente.c
        cliente.h
        geracao_particoes.c
        geracao_particoes.h
        lista_clientes.c
        lista_clientes.h
        Makefile
        nomes.c
        nomes.h
        test_geracao_particoes.c
        ufftest.h)
