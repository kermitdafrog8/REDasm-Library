#pragma once

#include <unordered_set>
#include <atomic>
#include <rdapi/types.h>
#include "algorithm/algorithm.h"
#include "../support/safe_ptr.h"

class Disassembler;
class Analyzer;

class Engine
{
    public:
        enum { EngineState_None, EngineState_Algorithm,  EngineState_Analyze,
               /* EngineState_Strings, */ EngineState_Unexplored,
               EngineState_CFG, EngineState_Signature, EngineState_Last };

    public:
        Engine(Disassembler* disassembler);
        ~Engine();
        size_t currentStep() const;
        void reset();
        void execute();
        void execute(size_t step);

    public:
        bool needsWeak() const;
        bool busy() const;
        void stop();

    private:
        //void stringsStep();
        void algorithmStep();
        void analyzeStep();
        void unexploredStep();
        void cfgStep();
        void signatureStep();

    private:
        void generateCfg(size_t funcindex);
        void notify(bool busy);

    private:
        bool m_busy{false};
        std::unordered_set<size_t> m_stepsdone;
        std::atomic<size_t> m_sigcount{0}, m_siganalyzed{0};
        std::unique_ptr<Analyzer> m_analyzer;
        //SignatureScanner m_sigscanner;
        //SignatureIdentifiers m_signatures;
        size_t m_currentstep{Engine::EngineState_None};
        Disassembler* m_disassembler;
        SafeAlgorithm& m_algorithm;
};

