#define RAPIDJSON_ASSERT(x)

#include "JsonParser.hpp"
#include "Core/Exception/NotImplementedException.hpp"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace Prog3::Api::Parser;
using namespace Prog3::Core::Model;
using namespace Prog3::Core::Exception;
using namespace rapidjson;
using namespace std;

string JsonParser::convertToApiString(Board &board) {
    throw NotImplementedException();
}

string JsonParser::convertToApiString(Column &column) {
    std::string items = "\"items\": [";
    for (Item i : column.getItems()) {
        items.append("\n");
        items.append(convertToApiString(i));
    }
    items.append("\n]");
    return "{\n\"id\": " +
           std::to_string(column.getId()) +
           ",\n\"name\": \"" +
           column.getName() +
           "\",\n\"position\": " +
           std::to_string(column.getPos()) +
           ",\n" +
           items +
           "\n}";
}

string JsonParser::convertToApiString(std::vector<Column> &columns) {
    throw NotImplementedException();
}

string JsonParser::convertToApiString(Item &item) {
    return "{\n\"id\": " +
           std::to_string(item.getId()) +
           ",\n\"title\": \"" +
           item.getTitle() +
           "\",\n\"position\": " +
           std::to_string(item.getPos()) +
           ",\n\"timestamp\": \"" +
           item.getTimestamp() +
           "\"\n}";
}

string JsonParser::convertToApiString(std::vector<Item> &items) {
    throw NotImplementedException();
}

std::optional<Column> JsonParser::convertColumnToModel(int columnId, std::string &request) {
    //Get name
    std::size_t nam1 = request.find_first_of("name");
    std::string nam = request.substr(nam1);
    nam1 = nam.find_first_of(",");
    nam = nam.substr(8, static_cast<int>(nam1) - 2);
    //Get position
    std::size_t pos1 = request.find_first_of("positio");
    std::string pos = request.substr(pos1);
    pos1 = pos.find_first_of(",");
    pos = pos.substr(11, static_cast<int>(pos1) - 1);
    int position = std::stoi(pos);
    //return result
    std::optional<Column> result = Column(columnId, nam, position);
    return result;
}

std::optional<Item> JsonParser::convertItemToModel(int itemId, std::string &request) {
    //Get title
    std::size_t title1 = request.find_first_of("title");
    std::string title = request.substr(title1);
    title1 = title.find_first_of(",");
    title = title.substr(9, static_cast<int>(title1) - 2);
    //Get position
    std::size_t pos1 = request.find_first_of("positio");
    std::string pos = request.substr(pos1);
    pos1 = pos.find_first_of(",");
    pos = pos.substr(11, static_cast<int>(pos1) - 1);
    int position = std::stoi(pos);
    //return result
    std::optional<Item> result = Item(itemId, title, position, "");
    return result;
}
