﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laborator1.Domain.Validator
{
    public class IllegalArgumentException : Exception
    {
        public IllegalArgumentException(string err) : base(err)
        {

        }
    }
}