const std::array<const Sequence<Interleaved2of5::ModuleType>, 10> Interleaved2of5::lookup_table  
{{
    { {1, true}, {1, false}, {3, true}, {3, false}, {1, true} }, /// '0': "| |||   |"
    { {3, true}, {1, false}, {1, true}, {1, false}, {3, true} }, /// '1': "||| | |||"
    { {1, true}, {3, false}, {1, true}, {1, false}, {3, true} }, /// '2': "|   | |||"
    { {3, true}, {3, false}, {1, true}, {1, false}, {1, true} }, /// '3': "|||   | |"
    { {1, true}, {1, false}, {3, true}, {1, false}, {3, true} }, /// '4': "| ||| |||"
    { {3, true}, {1, false}, {3, true}, {1, false}, {1, true} }, /// '5': "||| ||| |"
    { {1, true}, {3, false}, {3, true}, {1, false}, {1, true} }, /// '6': "|   ||| |"
    { {1, true}, {1, false}, {1, true}, {3, false}, {3, true} }, /// '7': "| |   |||"
    { {3, true}, {1, false}, {1, true}, {3, false}, {1, true} }, /// '8': "||| |   |"
    { {1, true}, {3, false}, {1, true}, {3, false}, {1, true} }, /// '9': "|   |   |"
 }};

const std::string Interleaved2of5::charset = "0123456789";

///   "|||| | |"
const Sequence<Interleaved2of5::ModuleType> Interleaved2of5::start_sequence = { {4, true}, {1, false}, {1, true}, {1, false}, {1, true} };

///   "||||   | |"
const Sequence<Interleaved2of5::ModuleType> Interleaved2of5::stop_sequence = { {4, true}, {3, false}, {1, true}, {1, false}, {1, true} };

Sequence<Interleaved2of5::ModuleType> Interleaved2of5::encode(const std::string& data)
{
    Sequence<ModuleType> sequence = start_sequence;
    for(std::size_t i = 0; i < data.size(); i += 2)
    {
        for(std::size_t j = 0; j < 5; ++j)
        {
            sequence += { lookup_table[data[i] - '0'][j].getWeight(), true };
            sequence += { lookup_table[data[i + 1] - '0'][j].getWeight(), false };
        }
    }
    sequence += stop_sequence;
    return sequence;
}

std::string Interleaved2of5::decode(const Sequence<Interleaved2of5::ModuleType> sequence)
{
    /// Ignore start + stop sequences (they are 5 modules each)
    auto size = (sequence.size() - 10) / 5;
    std::string data;
    data.reserve(size);
    for(std::string::size_type i = 0; i < size; i += 2)
    {
        Sequence<ModuleType> a, b;
        bool on = true;           
        for(std::size_t j = 0; j < 10;)
        {

            a += { sequence[5 + i * 5 + j++].getWeight(), on };
            b += { sequence[5 + i * 5 + j++].getWeight(), on };
            on = !on;
        }
        data.push_back('0' + static_cast<std::string::size_type>(std::find(lookup_table.begin(), lookup_table.end(), a) - lookup_table.begin()));
        data.push_back('0' + static_cast<std::string::size_type>(std::find(lookup_table.begin(), lookup_table.end(), b) - lookup_table.begin()));
    }
    return data;
}