To compile type:

g++ -g -o main main.C -I/usr/local/include -L/usr/local/lib -lwthttp -lwt -lboost_random -lboost_regex -lboost_signals -lboost_system -lboost_thread -lboost_filesystem -lboost_program_options -lboost_date_time

To execute type:

./main --docroot . --http-address 0.0.0.0 --http-port 8080

You can access the main application on localhost:8080 and the people application on localhost:8080/people
