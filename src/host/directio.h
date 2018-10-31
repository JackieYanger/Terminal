/*++
Copyright (c) Microsoft Corporation

Module Name:
- directio.h

Abstract:
- This file implements the NT console direct I/O API (read/write STDIO streams)

Author:
- KazuM Apr.19.1996

Revision History:
--*/

#pragma once

#include "conapi.h"
#include "inputBuffer.hpp"

class SCREEN_INFORMATION;

[[nodiscard]]
NTSTATUS TranslateOutputToUnicode(_Inout_ PCHAR_INFO OutputBuffer, _In_ COORD Size);
[[nodiscard]]
NTSTATUS TranslateOutputToPaddingUnicode(_Inout_ PCHAR_INFO OutputBuffer,
                                         _In_ COORD Size,
                                         _Inout_ PCHAR_INFO OutputBufferR);

[[nodiscard]]
HRESULT DoSrvWriteConsoleInput(_Inout_ InputBuffer* const pInputBuffer,
                               _Inout_ std::deque<std::unique_ptr<IInputEvent>>& events,
                               _Out_ size_t& eventsWritten,
                               const bool unicode,
                               const bool append);

[[nodiscard]]
NTSTATUS SrvReadConsoleOutput(_Inout_ PCONSOLE_API_MSG m, _Inout_ PBOOL ReplyPending);
[[nodiscard]]
NTSTATUS SrvWriteConsoleOutput(_Inout_ PCONSOLE_API_MSG m, _Inout_ PBOOL ReplyPending);
[[nodiscard]]
NTSTATUS SrvReadConsoleOutputString(_Inout_ PCONSOLE_API_MSG m, _Inout_ PBOOL ReplyPending);

[[nodiscard]]
NTSTATUS ConsoleCreateScreenBuffer(std::unique_ptr<ConsoleHandleData>& handle,
                                   _In_ PCONSOLE_API_MSG Message,
                                   _In_ PCD_CREATE_OBJECT_INFORMATION Information,
                                   _In_ PCONSOLE_CREATESCREENBUFFER_MSG a);

[[nodiscard]]
NTSTATUS DoSrvPrivatePrependConsoleInput(_Inout_ InputBuffer* const pInputBuffer,
                                         _Inout_ std::deque<std::unique_ptr<IInputEvent>>& events,
                                         _Out_ size_t& eventsWritten);

[[nodiscard]]
NTSTATUS DoSrvPrivateWriteConsoleControlInput(_Inout_ InputBuffer* const pInputBuffer,
                                              _In_ KeyEvent key);
