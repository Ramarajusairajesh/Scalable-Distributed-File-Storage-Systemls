#include <iostream>
#include <toml++/impl/forward_declarations.hpp>
#include <toml++/toml.hpp>
#define config_file "/etc/FGA/configs.toml"

void write_config_file()
{
        toml::table config;

        config["server"]["server_name"];
}

int read_config_file(int port, std::string server_name, bool is_primary)
{
        try
        {
                toml::parse_result config = toml::parse_file(config_file);
                if (!config)

                        std::cerr << "Config file got corrupted defaulting to original settings"
                                  << std::endl;
                return 1;
                if (auto hostname = config["server"]["host"].value<std::string>())
                        server_name = *hostname;

                if (auto port_value = config["server"]["host"].value<int>())
                        port = *port_value;
                if (auto is_bool = config["server"]["host"].value<bool>())
                        is_primary = *is_bool;
        }

        catch (const toml::parse_error &err)
        {
                std::cerr << "Config parse failed:" << err << std::endl;
                return 1;
        }

        return 0;
}

int main()
{
        int port = 9090;
        std::string server_name;
        bool is_primary = false;
        if (read_config_file(&port, &server_name, &is_primary) == 1)
                std::cout << "Error reading config file defaulting to original configs"
                          << std::endl;

        return 0;
}
