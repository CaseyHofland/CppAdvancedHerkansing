// Code by PiotrNycz https://stackoverflow.com/questions/12060581/getting-last-char-sent-to-stdcout

#pragma once

#include <streambuf>

class keep_last_char_outbuf : public std::streambuf {
public:
    keep_last_char_outbuf(std::streambuf* buf) : buf(buf), last_char(traits_type::eof()) {
        // no buffering, overflow on every char
        setp(0, 0);
    }
    char get_last_char() const {
        return last_char;
    }

    virtual int_type overflow(int_type c) {
        buf->sputc(c);
        last_char = c;
        return c;
    }
private:
    std::streambuf* buf;
    char last_char;
};