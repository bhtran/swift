//===--- ASTContext.h - AST Context Object ----------------------*- C++ -*-===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//
//
// This file defines the ASTContext interface.
//
//===----------------------------------------------------------------------===//

#ifndef SWIFT_ASTCONTEXT_H
#define SWIFT_ASTCONTEXT_H

namespace llvm {
  class BumpPtrAllocator;
  class SourceMgr;
}

namespace swift {
  class Type;

/// ASTContext - This object creates and owns the AST objects.
class ASTContext {
  ASTContext(const ASTContext&);           // DO NOT IMPLEMENT
  void operator=(const ASTContext&);       // DO NOT IMPLEMENT
  llvm::BumpPtrAllocator *Allocator;
public:
  ASTContext(llvm::SourceMgr &SourceMgr);
  ~ASTContext();
  
  /// SourceMgr - The source manager object.
  llvm::SourceMgr &SourceMgr;
  
  Type * const VoidType; /// VoidType - This is 'void'.
  Type * const IntType;  /// IntType - This is 'int'.
  
  void *Allocate(unsigned long Bytes, unsigned Alignment);
};
  
} // end namespace swift

#endif
