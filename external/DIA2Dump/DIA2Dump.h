#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <stdio.h>
#include <tchar.h>
#include <string.h>
#include <dia2.h>

#include "../../OrbitCore/Core.h"
#include "../../OrbitCore/Log.h"
#include "../../OrbitCore/OrbitType.h"
#include "../../OrbitCore/Pdb.h"
#include "../../OrbitCore/Params.h"

extern const wchar_t *g_szFilename;
extern IDiaDataSource *g_pDiaDataSource;
extern IDiaSession *g_pDiaSession;
extern IDiaSymbol *g_pGlobalSymbol;
extern DWORD g_dwMachineType;
extern DWORD g_NumFunctions;
extern DWORD g_NumUserTypes;

void PrintHelpOptions();
bool ParseArg(int , wchar_t *[]);

void CleanupDia();
bool LoadDataFromPdb(const wchar_t *, IDiaDataSource **, IDiaSession **, IDiaSymbol **);

void DumpAllPdbInfo(IDiaSession *, IDiaSymbol *);
bool DumpAllMods(IDiaSymbol *);
bool DumpAllPublics(IDiaSymbol *);
bool DumpAllFunctions(IDiaSymbol *);
bool DumpTypes(IDiaSymbol *);
bool DumpCompiland(IDiaSymbol *, const wchar_t *);
bool DumpAllSymbols(IDiaSymbol *);
bool DumpAllGlobals(IDiaSymbol *);
bool OrbitDumpAllGlobals(IDiaSymbol *);
bool DumpAllTypes(IDiaSymbol *);
bool DumpAllUDTs(IDiaSymbol *);
bool DumpAllEnums(IDiaSymbol *);
bool DumpAllTypedefs(IDiaSymbol *);
bool DumpAllOEMs(IDiaSymbol *);
bool DumpAllFiles(IDiaSession *, IDiaSymbol *);
bool DumpAllLines(IDiaSession *, IDiaSymbol *);
bool DumpAllLines(IDiaSession *, DWORD, DWORD);
bool DumpAllSecContribs(IDiaSession *);
bool DumpAllDebugStreams(IDiaSession *);
bool DumpAllInjectedSources(IDiaSession *);
bool DumpInjectedSource(IDiaSession *, const wchar_t *);
bool DumpAllSourceFiles(IDiaSession *, IDiaSymbol *);
bool DumpAllFPO(IDiaSession *);
bool DumpFPO(IDiaSession *, DWORD);
bool DumpFPO(IDiaSession *, IDiaSymbol *, const wchar_t *);
bool DumpSymbolWithRVA(IDiaSession *, DWORD, const wchar_t *);
bool DumpSymbolsWithRegEx(IDiaSymbol *, const wchar_t *, const wchar_t *);
bool DumpSymbolWithChildren(IDiaSymbol *, const wchar_t *);
bool DumpLines(IDiaSession *, DWORD);
bool DumpLines(IDiaSession *, IDiaSymbol *, const wchar_t *);
bool DumpType(IDiaSymbol *, const wchar_t *);
bool DumpLinesForSourceFile(IDiaSession *, const wchar_t *, DWORD);
bool DumpPublicSymbolsSorted(IDiaSession *, DWORD, DWORD, bool);
bool DumpLabel(IDiaSession *, DWORD);
bool DumpAnnotations(IDiaSession *, DWORD);
bool DumpMapToSrc(IDiaSession *, DWORD);
bool DumpMapFromSrc(IDiaSession *, DWORD);

HRESULT GetTable(IDiaSession *, REFIID, void **);

///////////////////////////////////////////////////////////////////
// Functions defined in regs.cpp
const wchar_t *SzNameC7Reg(USHORT, DWORD);
const wchar_t *SzNameC7Reg(USHORT);
