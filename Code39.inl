const std::string Code39::charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ-. $/+%";

const std::map<unsigned char, const Code39::SequenceType> Code39::charset_map = 
{
    std::make_pair(static_cast<unsigned char>('0'), Code39::SequenceType {{1, true}, {1, false}, {1, true}, {2, false}, {2, true}, {1, false}, {2, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('1'), Code39::SequenceType {{2, true}, {1, false}, {1, true}, {2, false}, {1, true}, {1, false}, {1, true}, {1, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('2'), Code39::SequenceType {{1, true}, {1, false}, {2, true}, {2, false}, {1, true}, {1, false}, {1, true}, {1, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('3'), Code39::SequenceType {{2, true}, {1, false}, {2, true}, {2, false}, {1, true}, {1, false}, {1, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('4'), Code39::SequenceType {{1, true}, {1, false}, {1, true}, {2, false}, {2, true}, {1, false}, {1, true}, {1, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('5'), Code39::SequenceType {{2, true}, {1, false}, {1, true}, {1, false}, {2, true}, {2, false}, {1, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('6'), Code39::SequenceType {{1, true}, {1, false}, {2, true}, {2, false}, {2, true}, {1, false}, {1, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('7'), Code39::SequenceType {{1, true}, {1, false}, {1, true}, {2, false}, {1, true}, {1, false}, {2, true}, {1, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('8'), Code39::SequenceType {{2, true}, {1, false}, {1, true}, {2, false}, {1, true}, {1, false}, {2, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('9'), Code39::SequenceType {{1, true}, {1, false}, {2, true}, {2, false}, {1, true}, {1, false}, {2, true}, {1, false}, {1, true}}), 
    // todo: incorrect encoding for 'A' -- need the specs!
    std::make_pair(static_cast<unsigned char>('A'), Code39::SequenceType {{1, true}, {1, false}, {2, true}, {2, false}, {1, true}, {1, false}, {2, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('B'), Code39::SequenceType {{1, true}, {1, false}, {2, true}, {1, false}, {1, true}, {2, false}, {1, true}, {1, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('C'), Code39::SequenceType {{2, true}, {1, false}, {2, true}, {1, false}, {1, true}, {2, false}, {1, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('D'), Code39::SequenceType {{1, true}, {1, false}, {1, true}, {1, false}, {2, true}, {2, false}, {1, true}, {1, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('E'), Code39::SequenceType {{2, true}, {1, false}, {1, true}, {2, false}, {2, true}, {2, false}, {1, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('F'), Code39::SequenceType {{1, true}, {1, false}, {2, true}, {1, false}, {2, true}, {2, false}, {1, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('G'), Code39::SequenceType {{1, true}, {1, false}, {1, true}, {1, false}, {1, true}, {2, false}, {2, true}, {1, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('H'), Code39::SequenceType {{2, true}, {1, false}, {1, true}, {1, false}, {1, true}, {2, false}, {2, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('I'), Code39::SequenceType {{1, true}, {1, false}, {2, true}, {1, false}, {1, true}, {2, false}, {2, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('J'), Code39::SequenceType {{1, true}, {1, false}, {1, true}, {1, false}, {2, true}, {2, false}, {2, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('K'), Code39::SequenceType {{2, true}, {1, false}, {1, true}, {1, false}, {1, true}, {1, false}, {1, true}, {2, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('L'), Code39::SequenceType {{1, true}, {1, false}, {2, true}, {1, false}, {1, true}, {1, false}, {1, true}, {2, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('M'), Code39::SequenceType {{2, true}, {1, false}, {2, true}, {1, false}, {1, true}, {1, false}, {1, true}, {2, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('N'), Code39::SequenceType {{1, true}, {1, false}, {1, true}, {1, false}, {2, true}, {1, false}, {1, true}, {2, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('O'), Code39::SequenceType {{2, true}, {1, false}, {1, true}, {1, false}, {2, true}, {1, false}, {1, true}, {2, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('P'), Code39::SequenceType {{1, true}, {1, false}, {2, true}, {1, false}, {2, true}, {1, false}, {1, true}, {2, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('Q'), Code39::SequenceType {{1, true}, {1, false}, {1, true}, {1, false}, {1, true}, {1, false}, {2, true}, {2, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('R'), Code39::SequenceType {{2, true}, {1, false}, {1, true}, {1, false}, {1, true}, {1, false}, {2, true}, {2, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('S'), Code39::SequenceType {{1, true}, {1, false}, {2, true}, {1, false}, {1, true}, {1, false}, {2, true}, {2, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('T'), Code39::SequenceType {{1, true}, {1, false}, {1, true}, {1, false}, {2, true}, {1, false}, {2, true}, {2, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('U'), Code39::SequenceType {{2, true}, {2, false}, {1, true}, {1, false}, {1, true}, {1, false}, {1, true}, {1, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('V'), Code39::SequenceType {{1, true}, {2, false}, {2, true}, {1, false}, {1, true}, {1, false}, {1, true}, {1, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('W'), Code39::SequenceType {{2, true}, {2, false}, {2, true}, {1, false}, {1, true}, {1, false}, {1, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('X'), Code39::SequenceType {{1, true}, {2, false}, {1, true}, {1, false}, {2, true}, {1, false}, {1, true}, {1, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('Y'), Code39::SequenceType {{2, true}, {2, false}, {1, true}, {1, false}, {2, true}, {1, false}, {1, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('Z'), Code39::SequenceType {{1, true}, {2, false}, {2, true}, {1, false}, {2, true}, {1, false}, {1, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('-'), Code39::SequenceType {{1, true}, {2, false}, {1, true}, {1, false}, {1, true}, {1, false}, {2, true}, {1, false}, {2, true}}), 
    std::make_pair(static_cast<unsigned char>('.'), Code39::SequenceType {{2, true}, {2, false}, {1, true}, {1, false}, {1, true}, {1, false}, {2, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>(' '), Code39::SequenceType {{1, true}, {2, false}, {2, true}, {1, false}, {1, true}, {1, false}, {2, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('$'), Code39::SequenceType {{1, true}, {2, false}, {1, true}, {2, false}, {1, true}, {2, false}, {1, true}, {1, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('/'), Code39::SequenceType {{1, true}, {2, false}, {1, true}, {2, false}, {1, true}, {1, false}, {1, true}, {2, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('+'), Code39::SequenceType {{1, true}, {2, false}, {1, true}, {1, false}, {1, true}, {2, false}, {1, true}, {2, false}, {1, true}}), 
    std::make_pair(static_cast<unsigned char>('%'), Code39::SequenceType {{1, true}, {1, false}, {1, true}, {2, false}, {1, true}, {2, false}, {1, true}, {2, false}, {1, true}})
};

const Code39::SequenceType Code39::start_sequence = 
    {{1, true}, {2, false}, {1, true}, {1, false}, {2, true}, {1, false}, {2, true}, {1, false}, {1, true}};

const Code39::SequenceType Code39::stop_sequence = Code39::start_sequence;

auto Code39::encode(const std::string& data) -> SequenceType
{
    /// Just a routine [START] [DATA[0]] ... [DATA[N - 1]] [CHECKSUM][STOP] encoding
    SequenceType rv = start_sequence;
    for(auto character : data)
    {
        rv += charset_map.at(character);
        rv += {1, false};
    }
    rv += charset_map.at(charset[checksum(data)]);
    rv += stop_sequence;
    return rv;
}

auto Code39::decode(const SequenceType sequence) -> std::string
{
    std::string rv;

    /// Each character in Code39 encoding is 9 modules in length
    /// So skip the start / stop sequences and checksum digit, then analyze the sequence 9 modules at a time
    for(auto offset = 9; offset < sequence.size() - 18; offset += 9)
    {
        SequenceType current {    sequence[offset], 
                                    sequence[offset + 1], 
                                    sequence[offset + 2], 
                                    sequence[offset + 3], 
                                    sequence[offset + 4], 
                                    sequence[offset + 5], 
                                    sequence[offset + 6], 
                                    sequence[offset + 7], 
                                    sequence[offset + 8] };

        /// TODO: Rethink linear complexity...
        for(auto pair : charset_map)
        {
            if(pair.second == current)
            {
                rv += pair.first;
                break;
            }
        }
    }
    return rv;
}

auto Code39::checksum(const std::string& data) -> unsigned char
{
    std::size_t checksum = 0;
    for(auto character : data)
    {
        checksum += charset.find(character);
    }
    return checksum % 43;
}
