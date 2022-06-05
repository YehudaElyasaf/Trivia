using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GuiClient
{
    public class RoomClosedException : Exception
    {
        public RoomClosedException()
        {
        }

        public RoomClosedException(string message)
            : base(message)
        {
        }

        public RoomClosedException(string message, Exception inner)
            : base(message, inner)
        {
        }
    }

    public class NoDataToReadException : Exception
    {
        public NoDataToReadException()
        {
        }

        public NoDataToReadException(string message)
            : base(message)
        {
        }

        public NoDataToReadException(string message, Exception inner)
            : base(message, inner)
        {
        }
    }
}
