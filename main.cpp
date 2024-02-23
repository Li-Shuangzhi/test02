#include <httplib.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    httplib::Server svr;

    svr.Get("/hello", [](const httplib::Request& req, httplib::Response& res) {
        json response_data = {
            {"message", "Hello, world!"}
        };
        res.set_content(response_data.dump(), "application/json");
        });

    svr.listen("localhost", 8080);

    return 0;
}
