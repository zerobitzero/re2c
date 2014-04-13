#include <stdio.h>
#define YYCTYPE unsigned short
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
Nd:
	/*!re2c
		re2c:yyfill:enable = 0;
		Nd = [\x30-\x39\u0660-\u0669\u06f0-\u06f9\u07c0-\u07c9\u0966-\u096f\u09e6-\u09ef\u0a66-\u0a6f\u0ae6-\u0aef\u0b66-\u0b6f\u0be6-\u0bef\u0c66-\u0c6f\u0ce6-\u0cef\u0d66-\u0d6f\u0e50-\u0e59\u0ed0-\u0ed9\u0f20-\u0f29\u1040-\u1049\u1090-\u1099\u17e0-\u17e9\u1810-\u1819\u1946-\u194f\u19d0-\u19d9\u1a80-\u1a89\u1a90-\u1a99\u1b50-\u1b59\u1bb0-\u1bb9\u1c40-\u1c49\u1c50-\u1c59\ua620-\ua629\ua8d0-\ua8d9\ua900-\ua909\ua9d0-\ua9d9\uaa50-\uaa59\uabf0-\uabf9\uff10-\uff19\U000104a0-\U000104a9\U00011066-\U0001106f\U0001d7ce-\U0001d7ff];
		Nd { goto Nd; }
		[^] { return YYCURSOR == limit; }
	*/
}
static const char buffer_Nd [] = "\x30\x00\x31\x00\x32\x00\x33\x00\x34\x00\x35\x00\x36\x00\x37\x00\x38\x00\x39\x00\x60\x06\x61\x06\x62\x06\x63\x06\x64\x06\x65\x06\x66\x06\x67\x06\x68\x06\x69\x06\xF0\x06\xF1\x06\xF2\x06\xF3\x06\xF4\x06\xF5\x06\xF6\x06\xF7\x06\xF8\x06\xF9\x06\xC0\x07\xC1\x07\xC2\x07\xC3\x07\xC4\x07\xC5\x07\xC6\x07\xC7\x07\xC8\x07\xC9\x07\x66\x09\x67\x09\x68\x09\x69\x09\x6A\x09\x6B\x09\x6C\x09\x6D\x09\x6E\x09\x6F\x09\xE6\x09\xE7\x09\xE8\x09\xE9\x09\xEA\x09\xEB\x09\xEC\x09\xED\x09\xEE\x09\xEF\x09\x66\x0A\x67\x0A\x68\x0A\x69\x0A\x6A\x0A\x6B\x0A\x6C\x0A\x6D\x0A\x6E\x0A\x6F\x0A\xE6\x0A\xE7\x0A\xE8\x0A\xE9\x0A\xEA\x0A\xEB\x0A\xEC\x0A\xED\x0A\xEE\x0A\xEF\x0A\x66\x0B\x67\x0B\x68\x0B\x69\x0B\x6A\x0B\x6B\x0B\x6C\x0B\x6D\x0B\x6E\x0B\x6F\x0B\xE6\x0B\xE7\x0B\xE8\x0B\xE9\x0B\xEA\x0B\xEB\x0B\xEC\x0B\xED\x0B\xEE\x0B\xEF\x0B\x66\x0C\x67\x0C\x68\x0C\x69\x0C\x6A\x0C\x6B\x0C\x6C\x0C\x6D\x0C\x6E\x0C\x6F\x0C\xE6\x0C\xE7\x0C\xE8\x0C\xE9\x0C\xEA\x0C\xEB\x0C\xEC\x0C\xED\x0C\xEE\x0C\xEF\x0C\x66\x0D\x67\x0D\x68\x0D\x69\x0D\x6A\x0D\x6B\x0D\x6C\x0D\x6D\x0D\x6E\x0D\x6F\x0D\x50\x0E\x51\x0E\x52\x0E\x53\x0E\x54\x0E\x55\x0E\x56\x0E\x57\x0E\x58\x0E\x59\x0E\xD0\x0E\xD1\x0E\xD2\x0E\xD3\x0E\xD4\x0E\xD5\x0E\xD6\x0E\xD7\x0E\xD8\x0E\xD9\x0E\x20\x0F\x21\x0F\x22\x0F\x23\x0F\x24\x0F\x25\x0F\x26\x0F\x27\x0F\x28\x0F\x29\x0F\x40\x10\x41\x10\x42\x10\x43\x10\x44\x10\x45\x10\x46\x10\x47\x10\x48\x10\x49\x10\x90\x10\x91\x10\x92\x10\x93\x10\x94\x10\x95\x10\x96\x10\x97\x10\x98\x10\x99\x10\xE0\x17\xE1\x17\xE2\x17\xE3\x17\xE4\x17\xE5\x17\xE6\x17\xE7\x17\xE8\x17\xE9\x17\x10\x18\x11\x18\x12\x18\x13\x18\x14\x18\x15\x18\x16\x18\x17\x18\x18\x18\x19\x18\x46\x19\x47\x19\x48\x19\x49\x19\x4A\x19\x4B\x19\x4C\x19\x4D\x19\x4E\x19\x4F\x19\xD0\x19\xD1\x19\xD2\x19\xD3\x19\xD4\x19\xD5\x19\xD6\x19\xD7\x19\xD8\x19\xD9\x19\x80\x1A\x81\x1A\x82\x1A\x83\x1A\x84\x1A\x85\x1A\x86\x1A\x87\x1A\x88\x1A\x89\x1A\x90\x1A\x91\x1A\x92\x1A\x93\x1A\x94\x1A\x95\x1A\x96\x1A\x97\x1A\x98\x1A\x99\x1A\x50\x1B\x51\x1B\x52\x1B\x53\x1B\x54\x1B\x55\x1B\x56\x1B\x57\x1B\x58\x1B\x59\x1B\xB0\x1B\xB1\x1B\xB2\x1B\xB3\x1B\xB4\x1B\xB5\x1B\xB6\x1B\xB7\x1B\xB8\x1B\xB9\x1B\x40\x1C\x41\x1C\x42\x1C\x43\x1C\x44\x1C\x45\x1C\x46\x1C\x47\x1C\x48\x1C\x49\x1C\x50\x1C\x51\x1C\x52\x1C\x53\x1C\x54\x1C\x55\x1C\x56\x1C\x57\x1C\x58\x1C\x59\x1C\x20\xA6\x21\xA6\x22\xA6\x23\xA6\x24\xA6\x25\xA6\x26\xA6\x27\xA6\x28\xA6\x29\xA6\xD0\xA8\xD1\xA8\xD2\xA8\xD3\xA8\xD4\xA8\xD5\xA8\xD6\xA8\xD7\xA8\xD8\xA8\xD9\xA8\x00\xA9\x01\xA9\x02\xA9\x03\xA9\x04\xA9\x05\xA9\x06\xA9\x07\xA9\x08\xA9\x09\xA9\xD0\xA9\xD1\xA9\xD2\xA9\xD3\xA9\xD4\xA9\xD5\xA9\xD6\xA9\xD7\xA9\xD8\xA9\xD9\xA9\x50\xAA\x51\xAA\x52\xAA\x53\xAA\x54\xAA\x55\xAA\x56\xAA\x57\xAA\x58\xAA\x59\xAA\xF0\xAB\xF1\xAB\xF2\xAB\xF3\xAB\xF4\xAB\xF5\xAB\xF6\xAB\xF7\xAB\xF8\xAB\xF9\xAB\x10\xFF\x11\xFF\x12\xFF\x13\xFF\x14\xFF\x15\xFF\x16\xFF\x17\xFF\x18\xFF\x19\xFF\x01\xD8\xA0\xDC\x01\xD8\xA1\xDC\x01\xD8\xA2\xDC\x01\xD8\xA3\xDC\x01\xD8\xA4\xDC\x01\xD8\xA5\xDC\x01\xD8\xA6\xDC\x01\xD8\xA7\xDC\x01\xD8\xA8\xDC\x01\xD8\xA9\xDC\x04\xD8\x66\xDC\x04\xD8\x67\xDC\x04\xD8\x68\xDC\x04\xD8\x69\xDC\x04\xD8\x6A\xDC\x04\xD8\x6B\xDC\x04\xD8\x6C\xDC\x04\xD8\x6D\xDC\x04\xD8\x6E\xDC\x04\xD8\x6F\xDC\x35\xD8\xCE\xDF\x35\xD8\xCF\xDF\x35\xD8\xD0\xDF\x35\xD8\xD1\xDF\x35\xD8\xD2\xDF\x35\xD8\xD3\xDF\x35\xD8\xD4\xDF\x35\xD8\xD5\xDF\x35\xD8\xD6\xDF\x35\xD8\xD7\xDF\x35\xD8\xD8\xDF\x35\xD8\xD9\xDF\x35\xD8\xDA\xDF\x35\xD8\xDB\xDF\x35\xD8\xDC\xDF\x35\xD8\xDD\xDF\x35\xD8\xDE\xDF\x35\xD8\xDF\xDF\x35\xD8\xE0\xDF\x35\xD8\xE1\xDF\x35\xD8\xE2\xDF\x35\xD8\xE3\xDF\x35\xD8\xE4\xDF\x35\xD8\xE5\xDF\x35\xD8\xE6\xDF\x35\xD8\xE7\xDF\x35\xD8\xE8\xDF\x35\xD8\xE9\xDF\x35\xD8\xEA\xDF\x35\xD8\xEB\xDF\x35\xD8\xEC\xDF\x35\xD8\xED\xDF\x35\xD8\xEE\xDF\x35\xD8\xEF\xDF\x35\xD8\xF0\xDF\x35\xD8\xF1\xDF\x35\xD8\xF2\xDF\x35\xD8\xF3\xDF\x35\xD8\xF4\xDF\x35\xD8\xF5\xDF\x35\xD8\xF6\xDF\x35\xD8\xF7\xDF\x35\xD8\xF8\xDF\x35\xD8\xF9\xDF\x35\xD8\xFA\xDF\x35\xD8\xFB\xDF\x35\xD8\xFC\xDF\x35\xD8\xFD\xDF\x35\xD8\xFE\xDF\x35\xD8\xFF\xDF\x00\x00";
int main ()
{
	if (!scan (reinterpret_cast<const YYCTYPE *> (buffer_Nd), reinterpret_cast<const YYCTYPE *> (buffer_Nd + sizeof (buffer_Nd) - 1)))
		printf("test 'Nd' failed\n");
}