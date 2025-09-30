cmake_minimum_required(VERSION 3.16)
project(async_echo_server)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создание исполняемого файла
add_executable(${PROJECT_NAME}
        main.cpp
        EchoServer.h
        EchoServer.cpp
        Session.h
        Session.cpp
)

set(BOOST_ROOT "C:/boost")
target_include_directories(async_echo_server PRIVATE ${BOOST_ROOT})

# Пример использования
add_executable(my_app main.cpp)
target_include_directories(my_app PRIVATE ${BOOST_ROOT})

# Линковка с системными библиотеками Windows
target_link_libraries(${PROJECT_NAME} PRIVATE
        ws2_32
        mswsock
        advapi32
)

# Опции компилятора для Windows
if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE
            WIN32_LEAN_AND_MEAN
            _WIN32_WINNT=0x0601
            BOOST_ASIO_DISABLE_IOCP=1  # Отключаем IOCP для MinGW
    )
endif()

target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall -Wextra -pedantic
)