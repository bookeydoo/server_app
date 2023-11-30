#include<iostream>
#include<boost/asio.hpp>
#include<boost/asio/buffer.hpp>
#include<boost/asio/write.hpp>
#include<boost/asio/ip/tcp.hpp>
#include<string>

using boost::asio::ip::tcp;

	std::string getData(tcp::socket& socket) {
			boost::asio::streambuf buffer;
			read_until(socket, buffer, "\n");
	std::string data(boost::asio::buffers_begin(buffer.data()), boost::asio::buffers_end(buffer.data()));
	buffer.consume(buffer.size()); 
	return data;	}


		void sendata(tcp::socket& socket, const std::string& message){
			boost::asio::write(socket,boost::asio::buffer(message+"\n"));
		}
		


		
		using namespace boost::asio ;

		int main(int argc, char* argv) {
			try
			{

				
				boost::asio::io_service Iostart;

				tcp::acceptor acceptor_server(Iostart, tcp::endpoint(tcp::v4(), 9999));


				tcp::socket server_socket(Iostart);
				acceptor_server.accept(server_socket);
				
			
				//to read a username
				std::string username = getData(server_socket);
				username.pop_back();

			/*	if (usercount == 2) {
					acceptor_server.close();
				}*/

				std::string response, reply;
				reply = "hello" + username;
				std::cout << "Server:" << reply << "\n dont forget to write " << "\"exit\"" << std::endl;
				sendata(server_socket, reply);

				while (true) {
					response = getData(server_socket);
					response.pop_back();

					if (response == "exit") {
						std::cout << username << "is leaving !" << std::endl;
						break;
					}
					std::cout << username << ":" << response << std::endl;
					getline(std::cin, reply);
					sendata(server_socket, reply);

					if (reply == "exit") {
						break;
					}

				}return 0;
			}
			catch (const std::exception&)
			{

			}

		}
