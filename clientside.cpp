

#include <boost/asio.hpp>
#include <iostream>
using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

string getData(tcp::socket& socket)
{
    boost::asio::streambuf buffer;
    boost::asio::read_until(socket, buffer, "\n");
    
    std::string data (buffers_begin(buffer.data()), buffers_end(buffer.data()));
    buffer.consume(buffer.size());
    return data;
}

void sendData(tcp::socket& socket, const string& message)
{
    write(socket,
        buffer(message + "\n"));
}

int main(int argc, char* argv[])
{
    io_service io_service;
    // socket creation
    ip::tcp::socket client_socket(io_service);

    client_socket
        .connect(
            tcp::endpoint(
                address::from_string("127.0.0.1"),
                9999));

    // Getting username from user
    cout << "Enter your name: ";
    string u_name, reply, response;
    getline(cin, u_name);

    // Sending username to another end
    // to initiate the conversation
    sendData(client_socket, u_name);

    // Infinite loop for chit-chat
    while (true) {

        // Fetching response
        response = getData(client_socket);

        // Popping last character "\n"
        response.pop_back();

        // Validating if the connection has to be closed
        if (response == "exit") {
            cout << "Connection terminated" << endl;
            break;
        }
        cout << "Server: " << response << endl;

        // Reading new message from input stream
        cout << u_name << ": ";
        getline(cin, reply);
        sendData(client_socket, reply);

        if (reply == "exit")
            break;
    }
    return 0;
}
