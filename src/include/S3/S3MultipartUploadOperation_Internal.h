/*
 * Copyright 2010-2013 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#import <Foundation/Foundation.h>
#import "AmazonServiceRequest.h"
#import "AmazonS3Client.h"

typedef void (^AbortMultipartUploadBlock)();

@protocol AmazonCredentialsProvider;

@interface S3MultipartUploadOperation_Internal : NSOperation <AmazonServiceRequestDelegate>
{
    BOOL _isExecuting;
    BOOL _isFinished;
    AmazonS3Client *_s3;
    S3PutObjectRequest *_request;
    AmazonServiceResponse *_response;
    NSError *_error;
    NSException *_exception;
    NSUInteger _partSize;
    NSUInteger _contentLength;
    NSUInteger _currentPartNo;
    NSInteger _numberOfParts;
    NSInteger _retryCount;
    AbortMultipartUploadBlock _abortMultipartUpload;
    S3InitiateMultipartUploadRequest *_initRequest;
    S3InitiateMultipartUploadResponse *_initResponse;
    S3MultipartUpload *_multipartUpload;
    S3CompleteMultipartUploadRequest *_completeRequest;
    NSData *_dataForPart;
}

@property (nonatomic, retain) AmazonS3Client *s3;
@property (nonatomic, retain) S3PutObjectRequest *request;
@property (nonatomic, retain) AmazonServiceResponse *response;
@property (nonatomic, retain) NSError *error;
@property (nonatomic, retain) NSException *exception;
@property (nonatomic, assign) int64_t partSize;

@end
