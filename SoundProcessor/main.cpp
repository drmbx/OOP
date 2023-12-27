#include <iostream>
#include <cstdint>

struct WavHeader {
    char riff_id[4]{0};
    int32_t chunk_size{0};
    char format[4]{0};
    char fmt_id[4]{0};
    int32_t fmt_sub_chunk_size{0};
    int16_t audio_format{0};
    int16_t num_channels{0};
    int32_t sample_rate{0};
    int32_t byte_rate{0};
    int16_t block_align{0};
    int16_t bits_per_sample{0};
    char data_id[4]{0};
    int32_t data_sub_chunk_size{0};
};

class Audio {
public:
    explicit Audio(const std::string& file_name) {

    }

private:
    WavHeader header_;

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
