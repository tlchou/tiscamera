

#include "MemoryBuffer.h"

#include <cstring>
#include <cstdlib>

using namespace tcam;


MemoryBuffer::MemoryBuffer (const struct tcam_image_buffer& buf)
    : buffer(buf), lock_count(0)
{}


MemoryBuffer::~MemoryBuffer ()
{}


tcam_image_buffer MemoryBuffer::getImageBuffer ()
{
    return buffer;
}

void MemoryBuffer::set_image_buffer (tcam_image_buffer buf)
{
    this->buffer = buf;
}


unsigned char* MemoryBuffer::get_data ()
{
    return buffer.pData;
}


struct tcam_stream_statistics MemoryBuffer::get_statistics () const
{
    return buffer.statistics;
}


bool MemoryBuffer::set_statistics (const struct tcam_stream_statistics& stats)
{
    buffer.statistics = stats;;

    return true;
}


bool MemoryBuffer::lock ()
{
    lock_count = 1;
    return true;
}


bool MemoryBuffer::unlock ()
{
    lock_count = 0;
    return true;
}


bool MemoryBuffer::is_locked () const
{
    if (lock_count == 0)
    {
        return false;
    }
    return true;
}


void MemoryBuffer::clear ()
{
    memset(buffer.pData, 0, buffer.length);
}
