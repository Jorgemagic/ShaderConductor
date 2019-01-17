/*
 * ShaderConductor
 *
 * Copyright (c) Microsoft Corporation. All rights reserved.
 * Licensed under the MIT License.
 *
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
 * to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED *AS IS*, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <ShaderConductor/ShaderConductor.hpp>

using namespace ShaderConductor;

struct SourceDescription
{
    const char* source;    
    const char* entryPoint;
    ShaderStage stage;  
	bool rowMajorByDefault;
    int shiftAllTexturesBindings;
    bool columnMajorByDefault;
    int shiftAllSamplersBindings;
    int shiftAllCBuffersBindings;
    int shiftAllUABuffersBindings;
};

struct TargetDescription
{
    ShadingLanguage shadingLanguage;
    const char* version;
};

struct ResultDescription
{   
    bool isText;
    char* target;
    int targetSize;
    bool hasError;
    char* errorWarningMsg;
};

struct DisassembleDescription
{
    ShadingLanguage language;
    int binarySize;
    char* binary;
};

char* binaryArray;
char* msgArray;

#define DLLEXPORT extern "C" __declspec(dllexport)

DLLEXPORT void Compile(SourceDescription* source, TargetDescription* target, ResultDescription* result);

DLLEXPORT void Disassemble(DisassembleDescription* source, ResultDescription* result);

DLLEXPORT void FreeResources();
