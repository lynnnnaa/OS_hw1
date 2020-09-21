#include <unistd.h>
#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <algorithm>

// split string p_line into a vector of strings (words)
// the delimiters are 1 or more whitespaces
std::vector<std::string>
split( const std::string & p_line)
{
  auto line = p_line + " ";
  std::vector<std::string> res;
  bool in_str = false;
  std::string curr_word = "";
  for( auto c : line) {
    if( isspace(c)) {
      if( in_str)
        res.push_back(curr_word);
      in_str = false;
      curr_word = "";
    }
    else {
      curr_word.push_back(c);
      in_str = true;
    }
  }
  return res;
}

// reads in a line from STDIN
// reads until newline or EOF,
// returns an empty string if EOF is hit immediately
// result includes "\n" if present
std::string
stdin_readline()
{
  std::string result;
  char c;
  while( 1 == read( STDIN_FILENO, & c, 1)) {
    result.push_back(c);
    if( c == '\n') break;
  }
  return result;
}

// returns a string that is reversed
std::string
reversed_string( const std::string & s)
{
  auto result = s;
  reverse( result.begin(), result.end());
  return result;
}

int
main()
{
  std::string max_pali;
  while(1) {
    std::string line = stdin_readline();
    if( line.size() == 0) break;
    for( char & c : line) c = tolower(c);
    auto words = split( line);
    for( auto word : words) {
      if( word.size() <= max_pali.size()) continue;
      if( word == reversed_string(word))
        max_pali = word;
    }
  }
  printf("Longest palindrome: %s\n", max_pali.c_str());

  return 0;
}

