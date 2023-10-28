/*
 * Copyright (c) 2023 Eve
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

// gcc -c parent-sick.c

enum ErrorCode长辈生病 {
  SUCCESS = 0,
  Error长辈不去医院 = 10001,
  Error医生违法 = 10101,
  Error医院院长违法 = 10102,
  Error制药公司违法 = 10103,
  Error医疗器械公司违法 = 10104
};

void *劝去医院(void *);
void *去医院(void *);
void *询问病好了(void *);
void *调查医院资料(void *, void *);
void *有问题(void *);
void *Get医生(void *);
void *Get医院院长(void *);
void *Get制药公司(void *);
void *Get医疗器械公司(void *);
int Handle起诉(void *, void *);

int Handle长辈生病(void *person)
{
  void *hospital, *documents;

  if (!劝去医院(person) && !劝去医院(person) && !劝去医院(person)) 
    return Error长辈不去医院;
  
  if (hospital = 去医院(person), 询问病好了(person))
    return SUCCESS;

  if (documents = 调查医院资料(hospital, person), 有问题(documents))
  {
    if (有问题(Get医生(documents)))
      if (Handle起诉(Get医生(documents), documents)) { /* TODO handle error */ }
      else return Error医生违法;

    if (有问题(Get医院院长(documents)))
      if (Handle起诉(Get医院院长(documents), documents)) { /* TODO handle error */ }
      else return Error医院院长违法;

    if (有问题(Get制药公司(documents)))
      if (Handle起诉(Get制药公司(documents), documents)) { /* TODO handle error */ }
      else return Error制药公司违法;

    if (有问题(Get医疗器械公司(documents)))
      if (Handle起诉(Get医疗器械公司(documents), documents)) { /* TODO handle error */ }
      else return Error医疗器械公司违法;

    // add more cases here...
  }
}

