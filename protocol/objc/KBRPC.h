// This file is autogenerated
#import "KBRObject.h"
#import "KBRRequest.h"
#import "KBRRequestParams.h"

@interface KBRStringKVPair : KBRObject
@property NSString *key;
@property NSString *value;
@end

@interface KBRStatus : KBRObject
@property NSInteger code;
@property NSString *name;
@property NSString *desc;
@property NSArray *fields; /*of KBRStringKVPair*/
@end

@interface KBRUID : NSData
@end

@interface KBRFOKID : KBRObject
@property NSData *pgpFingerprint;
@property NSData *kid;
@end

@interface KBRText : KBRObject
@property NSString *data;
@property BOOL markup;
@end

@interface KBRPgpIdentity : KBRObject
@property NSString *username;
@property NSString *comment;
@property NSString *email;
@end

@interface KBRImage : KBRObject
@property NSString *url;
@property NSInteger width;
@property NSInteger height;
@end

@interface KBRPublicKey : KBRObject
@property NSString *KID;
@property NSString *PGPFingerprint;
@property NSArray *PGPIdentities; /*of KBRPgpIdentity*/
@property BOOL isSibkey;
@property BOOL isEldest;
@property BOOL isWeb;
@property NSString *parentID;
@property NSString *deviceID;
@property NSString *deviceDescription;
@property long cTime;
@property long eTime;
@end

@interface KBRUser : KBRObject
@property KBRUID *uid;
@property NSString *username;
@property KBRImage *image;
@property NSArray *publicKeys; /*of KBRPublicKey*/
@end

@interface KBRDevice : KBRObject
@property NSString *type;
@property NSString *name;
@property NSString *deviceID;
@end

@interface KBRStream : KBRObject
@property NSInteger fd;
@end

@interface KBRSIGID : NSData
@end

@interface KBRBlockIdCombo : KBRObject
@property NSData *blockId;
@property NSInteger size;
@end

@interface KBRBlockInfo : KBRObject
@property KBRUID *chargedTo;
@property NSData *folder;
@property NSData *sKey;
@property NSData *nonce;
@end

@interface KBRBIndexRequest : KBRRequest
- (void)bIndexSessionWithSid:(NSString *)sid completion:(void (^)(NSError *error))completion;

- (void)getBIndexSKeyWithBid:(KBRBlockIdCombo *)bid completion:(void (^)(NSError *error, NSData *bytes))completion;

- (void)putBIndexWithBid:(KBRBlockIdCombo *)bid info:(KBRBlockInfo *)info completion:(void (^)(NSError *error))completion;

- (void)decBIndexReferenceWithBid:(KBRBlockIdCombo *)bid nonce:(NSData *)nonce chargedTo:(KBRUID *)chargedTo completion:(void (^)(NSError *error))completion;

- (void)incBIndexReferenceWithBid:(KBRBlockIdCombo *)bid nonce:(NSData *)nonce chargedTo:(KBRUID *)chargedTo completion:(void (^)(NSError *error))completion;

- (void)getBIndexAllWithBid:(KBRBlockIdCombo *)bid completion:(void (^)(NSError *error, NSArray *items))completion;

@end

@interface KBRBlockCharge : KBRObject
@property KBRBlockIdCombo *bid;
@property KBRUID *uid;
@end

@interface KBRBlockRequest : KBRRequest
- (void)blockSessionWithSid:(NSString *)sid completion:(void (^)(NSError *error))completion;

- (void)getBlockWithBid:(KBRBlockIdCombo *)bid completion:(void (^)(NSError *error, NSData *bytes))completion;

- (void)putBlockWithBid:(KBRBlockIdCombo *)bid buf:(NSData *)buf completion:(void (^)(NSError *error))completion;

@end

@interface KBRBTCRequest : KBRRequest
- (void)registerBTCWithSessionID:(NSInteger)sessionID address:(NSString *)address force:(BOOL)force completion:(void (^)(NSError *error))completion;

@end

@interface KBRGetCurrentStatusRes : KBRObject
@property BOOL configured;
@property BOOL registered;
@property BOOL loggedIn;
@property KBRUser *user;
@end

@interface KBRConfig : KBRObject
@property NSString *serverURI;
@property NSString *socketFile;
@property BOOL gpgExists;
@property NSString *gpgPath;
@property NSString *version;
@property NSString *path;
@property NSString *configPath;
@end

@interface KBRConfigRequest : KBRRequest
- (void)getCurrentStatus:(void (^)(NSError *error, KBRGetCurrentStatusRes *getCurrentStatusRes))completion;

- (void)getConfig:(void (^)(NSError *error, KBRConfig *config))completion;

@end

@interface KBRCryptoRequest : KBRRequest
- (void)signWithSessionID:(NSInteger)sessionID msg:(NSData *)msg reason:(NSString *)reason completion:(void (^)(NSError *error, NSData *bytes))completion;

@end

@interface KBRCtlRequest : KBRRequest
- (void)stop:(void (^)(NSError *error))completion;

- (void)logRotate:(void (^)(NSError *error))completion;

@end

@interface KBRDeviceRequest : KBRRequest
- (void)deviceListWithSessionID:(NSInteger)sessionID completion:(void (^)(NSError *error, NSArray *items))completion;

- (void)deviceAddWithSessionID:(NSInteger)sessionID secretPhrase:(NSString *)secretPhrase completion:(void (^)(NSError *error))completion;

- (void)deviceAddCancelWithSessionID:(NSInteger)sessionID completion:(void (^)(NSError *error))completion;

@end

@interface KBRDoctorRequest : KBRRequest
- (void)doctorWithSessionID:(NSInteger)sessionID completion:(void (^)(NSError *error))completion;

@end

typedef NS_ENUM (NSInteger, KBRDoctorFixType) {
	KBRDoctorFixTypeNone,
	KBRDoctorFixTypeAddEldestDevice,
	KBRDoctorFixTypeAddSiblingDevice,
};
@interface KBRDoctorSignerOpts : KBRObject
@property BOOL otherDevice;
@property BOOL pgp;
@property BOOL internal;
@end

@interface KBRDoctorStatus : KBRObject
@property KBRDoctorFixType fix;
@property KBRDoctorSignerOpts *signerOpts;
@property NSArray *devices; /*of KBRDevice*/
@property KBRDevice *webDevice;
@property KBRDevice *currentDevice;
@end

@interface KBRDoctorUiRequest : KBRRequest
- (void)loginSelectWithSessionID:(NSInteger)sessionID currentUser:(NSString *)currentUser otherUsers:(NSArray *)otherUsers completion:(void (^)(NSError *error, NSString *str))completion;

- (void)displayStatusWithSessionID:(NSInteger)sessionID status:(KBRDoctorStatus *)status completion:(void (^)(NSError *error, BOOL b))completion;

- (void)displayResultWithSessionID:(NSInteger)sessionID message:(NSString *)message completion:(void (^)(NSError *error))completion;

@end

@interface KBRGPGKey : KBRObject
@property NSString *algorithm;
@property NSString *keyID;
@property NSString *creation;
@property NSString *expiration;
@property NSArray *identities; /*of string*/
@end

@interface KBRSelectKeyRes : KBRObject
@property NSString *keyID;
@property BOOL doSecretPush;
@end

@interface KBRGpgUiRequest : KBRRequest
- (void)wantToAddGPGKeyWithSessionID:(NSInteger)sessionID completion:(void (^)(NSError *error, BOOL b))completion;

- (void)selectKeyAndPushOptionWithSessionID:(NSInteger)sessionID keys:(NSArray *)keys completion:(void (^)(NSError *error, KBRSelectKeyRes *selectKeyRes))completion;

- (void)selectKeyWithSessionID:(NSInteger)sessionID keys:(NSArray *)keys completion:(void (^)(NSError *error, NSString *str))completion;

@end

typedef NS_ENUM (NSInteger, KBRTrackDiffType) {
	KBRTrackDiffTypeNone,
	KBRTrackDiffTypeError,
	KBRTrackDiffTypeClash,
	KBRTrackDiffTypeDeleted,
	KBRTrackDiffTypeUpgraded,
	KBRTrackDiffTypeNew,
	KBRTrackDiffTypeRemoteFail,
	KBRTrackDiffTypeRemoteWorking,
	KBRTrackDiffTypeRemoteChanged,
};
@interface KBRTrackDiff : KBRObject
@property KBRTrackDiffType type;
@property NSString *displayMarkup;
@end

@interface KBRTrackSummary : KBRObject
@property NSString *username;
@property NSInteger time;
@property BOOL isRemote;
@end

@interface KBRIdentifyOutcome : KBRObject
@property NSString *username;
@property KBRStatus *status;
@property NSArray *warnings; /*of string*/
@property KBRTrackSummary *trackUsed;
@property NSInteger numTrackFailures;
@property NSInteger numTrackChanges;
@property NSInteger numProofFailures;
@property NSInteger numDeleted;
@property NSInteger numProofSuccesses;
@property NSArray *deleted; /*of KBRTrackDiff*/
@property BOOL localOnly;
@property BOOL approveRemote;
@end

@interface KBRIdentifyRes : KBRObject
@property KBRUser *user;
@property KBRIdentifyOutcome *outcome;
@end

@interface KBRIdentifyRequest : KBRRequest
- (void)identifyWithSessionID:(NSInteger)sessionID userAssertion:(NSString *)userAssertion trackStatement:(BOOL)trackStatement completion:(void (^)(NSError *error, KBRIdentifyRes *identifyRes))completion;

- (void)identifyDefaultWithSessionID:(NSInteger)sessionID userAssertion:(NSString *)userAssertion completion:(void (^)(NSError *error, KBRIdentifyRes *identifyRes))completion;

@end

@interface KBRProofStatus : KBRObject
@property NSInteger state;
@property NSInteger status;
@property NSString *desc;
@end

@interface KBRRemoteProof : KBRObject
@property NSInteger proofType;
@property NSString *key;
@property NSString *value;
@property NSString *displayMarkup;
@property KBRSIGID *sigId;
@property NSInteger mtime;
@end

@interface KBRIdentifyRow : KBRObject
@property NSInteger rowId;
@property KBRRemoteProof *proof;
@property KBRTrackDiff *trackDiff;
@end

@interface KBRIdentifyKey : KBRObject
@property NSData *pgpFingerprint;
@property NSData *KID;
@property KBRTrackDiff *trackDiff;
@end

@interface KBRCryptocurrency : KBRObject
@property NSInteger rowId;
@property NSData *pkhash;
@property NSString *address;
@end

@interface KBRIdentity : KBRObject
@property KBRStatus *status;
@property NSInteger whenLastTracked;
@property NSArray *keys; /*of KBRIdentifyKey*/
@property NSArray *proofs; /*of KBRIdentifyRow*/
@property NSArray *cryptocurrency; /*of KBRCryptocurrency*/
@property NSArray *deleted; /*of KBRTrackDiff*/
@end

@interface KBRSigHint : KBRObject
@property NSString *remoteId;
@property NSString *humanUrl;
@property NSString *apiUrl;
@property NSString *checkText;
@end

@interface KBRCheckResult : KBRObject
@property KBRProofStatus *proofStatus;
@property NSInteger timestamp;
@property NSString *displayMarkup;
@end

@interface KBRLinkCheckResult : KBRObject
@property NSInteger proofId;
@property KBRProofStatus *proofStatus;
@property KBRCheckResult *cached;
@property KBRTrackDiff *diff;
@property KBRTrackDiff *remoteDiff;
@property KBRSigHint *hint;
@end

@interface KBRFinishAndPromptRes : KBRObject
@property BOOL trackLocal;
@property BOOL trackRemote;
@end

@interface KBRIdentifyUiRequest : KBRRequest
- (void)finishAndPromptWithSessionID:(NSInteger)sessionID outcome:(KBRIdentifyOutcome *)outcome completion:(void (^)(NSError *error, KBRFinishAndPromptRes *finishAndPromptRes))completion;

- (void)finishWebProofCheckWithSessionID:(NSInteger)sessionID rp:(KBRRemoteProof *)rp lcr:(KBRLinkCheckResult *)lcr completion:(void (^)(NSError *error))completion;

- (void)finishSocialProofCheckWithSessionID:(NSInteger)sessionID rp:(KBRRemoteProof *)rp lcr:(KBRLinkCheckResult *)lcr completion:(void (^)(NSError *error))completion;

- (void)displayCryptocurrencyWithSessionID:(NSInteger)sessionID c:(KBRCryptocurrency *)c completion:(void (^)(NSError *error))completion;

- (void)displayKeyWithSessionID:(NSInteger)sessionID fokid:(KBRFOKID *)fokid diff:(KBRTrackDiff *)diff completion:(void (^)(NSError *error))completion;

- (void)reportLastTrackWithSessionID:(NSInteger)sessionID track:(KBRTrackSummary *)track completion:(void (^)(NSError *error))completion;

- (void)launchNetworkChecksWithSessionID:(NSInteger)sessionID idKb:(KBRIdentity *)idKb user:(KBRUser *)user completion:(void (^)(NSError *error))completion;

- (void)displayTrackStatementWithSessionID:(NSInteger)sessionID stmt:(NSString *)stmt completion:(void (^)(NSError *error))completion;

- (void)startWithSessionID:(NSInteger)sessionID username:(NSString *)username completion:(void (^)(NSError *error))completion;

- (void)finishWithSessionID:(NSInteger)sessionID completion:(void (^)(NSError *error))completion;

@end

typedef NS_ENUM (NSInteger, KBRDeviceSignerKind) {
	KBRDeviceSignerKindDevice,
	KBRDeviceSignerKindPgp,
};
typedef NS_ENUM (NSInteger, KBRSelectSignerAction) {
	KBRSelectSignerActionSign,
	KBRSelectSignerActionCancel,
	KBRSelectSignerActionResetAccount,
};
@interface KBRDeviceSigner : KBRObject
@property KBRDeviceSignerKind kind;
@property NSString *deviceID;
@property NSString *deviceName;
@end

@interface KBRSelectSignerRes : KBRObject
@property KBRSelectSignerAction action;
@property KBRDeviceSigner *signer;
@end

typedef NS_ENUM (NSInteger, KBRKexStatusCode) {
	KBRKexStatusCodeStartSend,
	KBRKexStatusCodeHelloWait,
	KBRKexStatusCodeHelloReceived,
	KBRKexStatusCodePleaseSignSend,
	KBRKexStatusCodeDoneWait,
	KBRKexStatusCodeDoneReceived,
	KBRKexStatusCodeStartWait,
	KBRKexStatusCodeStartReceived,
	KBRKexStatusCodeHelloSend,
	KBRKexStatusCodePleaseSignWait,
	KBRKexStatusCodePleaseSignReceived,
	KBRKexStatusCodeDoneSend,
	KBRKexStatusCodeEnd,
};
@interface KBRLocksmithUiRequest : KBRRequest
- (void)promptDeviceNameWithSessionID:(NSInteger)sessionID completion:(void (^)(NSError *error, NSString *str))completion;

- (void)selectSignerWithSessionID:(NSInteger)sessionID devices:(NSArray *)devices hasPGP:(BOOL)hasPGP completion:(void (^)(NSError *error, KBRSelectSignerRes *selectSignerRes))completion;

- (void)displaySecretWordsWithSessionID:(NSInteger)sessionID secret:(NSString *)secret deviceNameExisting:(NSString *)deviceNameExisting deviceNameToAdd:(NSString *)deviceNameToAdd completion:(void (^)(NSError *error))completion;

- (void)kexStatusWithSessionID:(NSInteger)sessionID msg:(NSString *)msg code:(KBRKexStatusCode)code completion:(void (^)(NSError *error))completion;

@end

typedef NS_ENUM (NSInteger, KBRLogLevel) {
	KBRLogLevelNone,
	KBRLogLevelDebug,
	KBRLogLevelInfo,
	KBRLogLevelNotice,
	KBRLogLevelWarn,
	KBRLogLevelError,
	KBRLogLevelCritical,
};
@interface KBRLogUiRequest : KBRRequest
- (void)logWithSessionID:(NSInteger)sessionID level:(KBRLogLevel)level text:(KBRText *)text completion:(void (^)(NSError *error))completion;

@end

@interface KBRConfiguredAccount : KBRObject
@property NSString *username;
@property BOOL hasStoredSecret;
@end

@interface KBRLoginRequest : KBRRequest
- (void)getConfiguredAccounts:(void (^)(NSError *error, NSArray *items))completion;

- (void)loginWithPromptWithSessionID:(NSInteger)sessionID username:(NSString *)username completion:(void (^)(NSError *error))completion;

- (void)loginWithStoredSecretWithSessionID:(NSInteger)sessionID username:(NSString *)username completion:(void (^)(NSError *error))completion;

- (void)loginWithPassphraseWithSessionID:(NSInteger)sessionID username:(NSString *)username passphrase:(NSString *)passphrase storeSecret:(BOOL)storeSecret completion:(void (^)(NSError *error))completion;

- (void)clearStoredSecretWithUsername:(NSString *)username completion:(void (^)(NSError *error))completion;

- (void)cancelLoginWithSessionID:(NSInteger)sessionID completion:(void (^)(NSError *error))completion;

- (void)logout:(void (^)(NSError *error))completion;

- (void)reset:(void (^)(NSError *error))completion;

@end

@interface KBRLoginUiRequest : KBRRequest
- (void)getEmailOrUsernameWithSessionID:(NSInteger)sessionID completion:(void (^)(NSError *error, NSString *str))completion;

@end

typedef NS_ENUM (NSInteger, KBRSignMode) {
	KBRSignModeAttached,
	KBRSignModeDetached,
	KBRSignModeClear,
};
@interface KBRPgpSignOptions : KBRObject
@property NSString *keyQuery;
@property KBRSignMode mode;
@property BOOL binaryIn;
@property BOOL binaryOut;
@end

@interface KBRPgpEncryptOptions : KBRObject
@property NSArray *recipients; /*of string*/
@property BOOL noSign;
@property BOOL noSelf;
@property BOOL binaryOut;
@property NSString *keyQuery;
@property BOOL localOnly;
@property BOOL approveRemote;
@end

@interface KBRPgpSigVerification : KBRObject
@property BOOL isSigned;
@property BOOL verified;
@property KBRUser *signer;
@property KBRPublicKey *signKey;
@end

@interface KBRPgpDecryptOptions : KBRObject
@property BOOL assertSigned;
@property NSString *signedBy;
@property BOOL localOnly;
@property BOOL approveRemote;
@end

@interface KBRPgpVerifyOptions : KBRObject
@property NSString *signedBy;
@property BOOL localOnly;
@property BOOL approveRemote;
@property NSData *signature;
@end

@interface KBRFingerprintAndKey : KBRObject
@property NSString *fingerprint;
@property NSString *key;
@property NSString *desc;
@end

@interface KBRPgpCreateUids : KBRObject
@property BOOL useDefault;
@property NSArray *ids; /*of KBRPgpIdentity*/
@end

@interface KBRPgpRequest : KBRRequest
- (void)pgpSignWithSessionID:(NSInteger)sessionID source:(KBRStream *)source sink:(KBRStream *)sink opts:(KBRPgpSignOptions *)opts completion:(void (^)(NSError *error))completion;

- (void)pgpPullWithSessionID:(NSInteger)sessionID userAsserts:(NSArray *)userAsserts completion:(void (^)(NSError *error))completion;

- (void)pgpEncryptWithSessionID:(NSInteger)sessionID source:(KBRStream *)source sink:(KBRStream *)sink opts:(KBRPgpEncryptOptions *)opts completion:(void (^)(NSError *error))completion;

- (void)pgpDecryptWithSessionID:(NSInteger)sessionID source:(KBRStream *)source sink:(KBRStream *)sink opts:(KBRPgpDecryptOptions *)opts completion:(void (^)(NSError *error, KBRPgpSigVerification *pgpSigVerification))completion;

- (void)pgpVerifyWithSessionID:(NSInteger)sessionID source:(KBRStream *)source opts:(KBRPgpVerifyOptions *)opts completion:(void (^)(NSError *error, KBRPgpSigVerification *pgpSigVerification))completion;

- (void)pgpImportWithSessionID:(NSInteger)sessionID key:(NSData *)key pushSecret:(BOOL)pushSecret completion:(void (^)(NSError *error))completion;

- (void)pgpExportWithSessionID:(NSInteger)sessionID secret:(BOOL)secret query:(NSString *)query completion:(void (^)(NSError *error, NSArray *items))completion;

- (void)pgpKeyGenWithPrimaryBits:(NSInteger)primaryBits subkeyBits:(NSInteger)subkeyBits createUids:(KBRPgpCreateUids *)createUids allowMulti:(BOOL)allowMulti doExport:(BOOL)doExport completion:(void (^)(NSError *error))completion;

- (void)pgpKeyGenDefaultWithCreateUids:(KBRPgpCreateUids *)createUids completion:(void (^)(NSError *error))completion;

- (void)pgpDeletePrimary:(void (^)(NSError *error))completion;

- (void)pgpSelectWithQuery:(NSString *)query allowMulti:(BOOL)allowMulti skipImport:(BOOL)skipImport completion:(void (^)(NSError *error))completion;

- (void)pgpUpdateWithSessionID:(NSInteger)sessionID all:(BOOL)all fingerprints:(NSArray *)fingerprints completion:(void (^)(NSError *error))completion;

@end

@interface KBRProveRequest : KBRRequest
- (void)proveWithSessionID:(NSInteger)sessionID service:(NSString *)service username:(NSString *)username force:(BOOL)force completion:(void (^)(NSError *error))completion;

@end

typedef NS_ENUM (NSInteger, KBRPromptOverwriteType) {
	KBRPromptOverwriteTypeSocial,
	KBRPromptOverwriteTypeSite,
};
@interface KBRProveUiRequest : KBRRequest
- (void)promptOverwriteWithSessionID:(NSInteger)sessionID account:(NSString *)account typ:(KBRPromptOverwriteType)typ completion:(void (^)(NSError *error, BOOL b))completion;

- (void)promptUsernameWithSessionID:(NSInteger)sessionID prompt:(NSString *)prompt prevError:(KBRStatus *)prevError completion:(void (^)(NSError *error, NSString *str))completion;

- (void)outputPrechecksWithSessionID:(NSInteger)sessionID text:(KBRText *)text completion:(void (^)(NSError *error))completion;

- (void)preProofWarningWithSessionID:(NSInteger)sessionID text:(KBRText *)text completion:(void (^)(NSError *error, BOOL b))completion;

- (void)outputInstructionsWithSessionID:(NSInteger)sessionID instructions:(KBRText *)instructions proof:(NSString *)proof completion:(void (^)(NSError *error))completion;

- (void)okToCheckWithSessionID:(NSInteger)sessionID name:(NSString *)name attempt:(NSInteger)attempt completion:(void (^)(NSError *error, BOOL b))completion;

- (void)displayRecheckWarningWithSessionID:(NSInteger)sessionID text:(KBRText *)text completion:(void (^)(NSError *error))completion;

@end

@interface KBRSessionToken : KBRObject
@property KBRUID *uid;
@property NSString *sid;
@property NSInteger generated;
@property NSInteger lifetime;
@end

@interface KBRQuotaRequest : KBRRequest
- (void)verifySessionWithSession:(NSString *)session completion:(void (^)(NSError *error, KBRSessionToken *sessionToken))completion;

@end

@interface KBRRevokeRequest : KBRRequest
- (void)revokeKeyWithSessionID:(NSInteger)sessionID idKb:(NSString *)idKb completion:(void (^)(NSError *error))completion;

- (void)revokeDeviceWithSessionID:(NSInteger)sessionID idKb:(NSString *)idKb completion:(void (^)(NSError *error))completion;

- (void)revokeSigsWithSessionID:(NSInteger)sessionID ids:(NSArray *)ids seqnos:(NSArray *)seqnos completion:(void (^)(NSError *error))completion;

@end

@interface KBRSecretEntryArg : KBRObject
@property NSString *desc;
@property NSString *prompt;
@property NSString *err;
@property NSString *cancel;
@property NSString *ok;
@property BOOL useSecretStore;
@end

@interface KBRSecretEntryRes : KBRObject
@property NSString *text;
@property BOOL canceled;
@property BOOL storeSecret;
@end

@interface KBRSecretUiRequest : KBRRequest
- (void)getSecretWithSessionID:(NSInteger)sessionID pinentry:(KBRSecretEntryArg *)pinentry terminal:(KBRSecretEntryArg *)terminal completion:(void (^)(NSError *error, KBRSecretEntryRes *secretEntryRes))completion;

- (void)getNewPassphraseWithTerminalPrompt:(NSString *)terminalPrompt pinentryDesc:(NSString *)pinentryDesc pinentryPrompt:(NSString *)pinentryPrompt retryMessage:(NSString *)retryMessage completion:(void (^)(NSError *error, NSString *str))completion;

- (void)getKeybasePassphraseWithSessionID:(NSInteger)sessionID username:(NSString *)username retry:(NSString *)retry completion:(void (^)(NSError *error, NSString *str))completion;

@end

@interface KBRSession : KBRObject
@property KBRUID *uid;
@property NSString *username;
@property NSString *token;
@property NSString *deviceSibkeyKid;
@property NSString *deviceSubkeyKid;
@end

@interface KBRSessionRequest : KBRRequest
- (void)currentSession:(void (^)(NSError *error, KBRSession *session))completion;

@end

@interface KBRSignupRes : KBRObject
@property BOOL passphraseOk;
@property BOOL postOk;
@property BOOL writeOk;
@end

@interface KBRSignupRequest : KBRRequest
- (void)checkUsernameAvailableWithUsername:(NSString *)username completion:(void (^)(NSError *error))completion;

- (void)signupWithEmail:(NSString *)email inviteCode:(NSString *)inviteCode passphrase:(NSString *)passphrase username:(NSString *)username deviceName:(NSString *)deviceName completion:(void (^)(NSError *error, KBRSignupRes *signupRes))completion;

- (void)inviteRequestWithEmail:(NSString *)email fullname:(NSString *)fullname notes:(NSString *)notes completion:(void (^)(NSError *error))completion;

@end

@interface KBRSig : KBRObject
@property NSInteger seqno;
@property NSString *sigIdDisplay;
@property NSString *type;
@property NSInteger ctime;
@property BOOL revoked;
@property BOOL active;
@property NSString *key;
@property NSString *body;
@end

@interface KBRSigTypes : KBRObject
@property BOOL track;
@property BOOL proof;
@property BOOL cryptocurrency;
@property BOOL self;
@end

@interface KBRSigListArgs : KBRObject
@property NSInteger sessionID;
@property NSString *username;
@property BOOL allKeys;
@property KBRSigTypes *types;
@property NSString *filterx;
@property BOOL verbose;
@property BOOL revoked;
@end

@interface KBRSigsRequest : KBRRequest
- (void)sigListWithArg:(KBRSigListArgs *)arg completion:(void (^)(NSError *error, NSArray *items))completion;

- (void)sigListJSONWithArg:(KBRSigListArgs *)arg completion:(void (^)(NSError *error, NSString *str))completion;

@end

@interface KBRStreamUiRequest : KBRRequest
- (void)closeWithS:(KBRStream *)s completion:(void (^)(NSError *error))completion;

- (void)readWithS:(KBRStream *)s sz:(NSInteger)sz completion:(void (^)(NSError *error, NSData *bytes))completion;

- (void)writeWithS:(KBRStream *)s buf:(NSData *)buf completion:(void (^)(NSError *error, NSInteger n))completion;

@end

@interface KBRTrackRequest : KBRRequest
- (void)trackWithSessionID:(NSInteger)sessionID theirName:(NSString *)theirName localOnly:(BOOL)localOnly approveRemote:(BOOL)approveRemote completion:(void (^)(NSError *error))completion;

- (void)untrackWithSessionID:(NSInteger)sessionID theirName:(NSString *)theirName completion:(void (^)(NSError *error))completion;

@end

@interface KBRUiRequest : KBRRequest
- (void)promptYesNoWithSessionID:(NSInteger)sessionID text:(KBRText *)text def:(BOOL)def completion:(void (^)(NSError *error, BOOL b))completion;

@end

@interface KBRTracker : KBRObject
@property KBRUID *tracker;
@property NSInteger status;
@property NSInteger mtime;
@end

@interface KBRTrackProof : KBRObject
@property NSString *proofType;
@property NSString *proofName;
@property NSString *idString;
@end

@interface KBRWebProof : KBRObject
@property NSString *hostname;
@property NSArray *protocols; /*of string*/
@end

@interface KBRProofs : KBRObject
@property NSArray *social; /*of KBRTrackProof*/
@property NSArray *web; /*of KBRWebProof*/
@property NSArray *publicKeys; /*of KBRPublicKey*/
@end

@interface KBRUserSummary : KBRObject
@property KBRUID *uid;
@property NSString *thumbnail;
@property NSString *username;
@property NSInteger idVersion;
@property NSString *fullName;
@property NSString *bio;
@property KBRProofs *proofs;
@property NSString *sigId;
@property long trackTime;
@end

@interface KBRUserRequest : KBRRequest
- (void)listTrackersWithSessionID:(NSInteger)sessionID uid:(KBRUID *)uid completion:(void (^)(NSError *error, NSArray *items))completion;

- (void)listTrackersByNameWithSessionID:(NSInteger)sessionID username:(NSString *)username completion:(void (^)(NSError *error, NSArray *items))completion;

- (void)listTrackersSelfWithSessionID:(NSInteger)sessionID completion:(void (^)(NSError *error, NSArray *items))completion;

- (void)loadUncheckedUserSummariesWithUids:(NSArray *)uids completion:(void (^)(NSError *error, NSArray *items))completion;

- (void)loadUserWithUid:(KBRUID *)uid username:(NSString *)username selfKb:(BOOL)selfKb completion:(void (^)(NSError *error, KBRUser *user))completion;

- (void)listTrackingWithFilter:(NSString *)filter completion:(void (^)(NSError *error, NSArray *items))completion;

- (void)listTrackingJsonWithFilter:(NSString *)filter verbose:(BOOL)verbose completion:(void (^)(NSError *error, NSString *str))completion;

- (void)searchWithSessionID:(NSInteger)sessionID query:(NSString *)query completion:(void (^)(NSError *error, NSArray *items))completion;

@end
@interface KBRBIndexSessionRequestParams : KBRRequestParams
@property NSString *sid;
@end
@interface KBRGetBIndexSKeyRequestParams : KBRRequestParams
@property KBRBlockIdCombo *bid;
@end
@interface KBRPutBIndexRequestParams : KBRRequestParams
@property KBRBlockIdCombo *bid;
@property KBRBlockInfo *info;
@end
@interface KBRDecBIndexReferenceRequestParams : KBRRequestParams
@property KBRBlockIdCombo *bid;
@property NSData *nonce;
@property KBRUID *chargedTo;
@end
@interface KBRIncBIndexReferenceRequestParams : KBRRequestParams
@property KBRBlockIdCombo *bid;
@property NSData *nonce;
@property KBRUID *chargedTo;
@end
@interface KBRGetBIndexAllRequestParams : KBRRequestParams
@property KBRBlockIdCombo *bid;
@end
@interface KBRBlockSessionRequestParams : KBRRequestParams
@property NSString *sid;
@end
@interface KBRGetBlockRequestParams : KBRRequestParams
@property KBRBlockIdCombo *bid;
@end
@interface KBRPutBlockRequestParams : KBRRequestParams
@property KBRBlockIdCombo *bid;
@property NSData *buf;
@end
@interface KBRRegisterBTCRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *address;
@property BOOL force;
@end
@interface KBRSignRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSData *msg;
@property NSString *reason;
@end
@interface KBRDeviceListRequestParams : KBRRequestParams
@property NSInteger sessionID;
@end
@interface KBRDeviceAddRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *secretPhrase;
@end
@interface KBRDeviceAddCancelRequestParams : KBRRequestParams
@property NSInteger sessionID;
@end
@interface KBRDoctorRequestParams : KBRRequestParams
@property NSInteger sessionID;
@end
@interface KBRLoginSelectRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *currentUser;
@property NSArray *otherUsers;
@end
@interface KBRDisplayStatusRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRDoctorStatus *status;
@end
@interface KBRDisplayResultRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *message;
@end
@interface KBRWantToAddGPGKeyRequestParams : KBRRequestParams
@property NSInteger sessionID;
@end
@interface KBRSelectKeyAndPushOptionRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSArray *keys;
@end
@interface KBRSelectKeyRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSArray *keys;
@end
@interface KBRIdentifyRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *userAssertion;
@property BOOL trackStatement;
@end
@interface KBRIdentifyDefaultRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *userAssertion;
@end
@interface KBRFinishAndPromptRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRIdentifyOutcome *outcome;
@end
@interface KBRFinishWebProofCheckRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRRemoteProof *rp;
@property KBRLinkCheckResult *lcr;
@end
@interface KBRFinishSocialProofCheckRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRRemoteProof *rp;
@property KBRLinkCheckResult *lcr;
@end
@interface KBRDisplayCryptocurrencyRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRCryptocurrency *c;
@end
@interface KBRDisplayKeyRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRFOKID *fokid;
@property KBRTrackDiff *diff;
@end
@interface KBRReportLastTrackRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRTrackSummary *track;
@end
@interface KBRLaunchNetworkChecksRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRIdentity *id;
@property KBRUser *user;
@end
@interface KBRDisplayTrackStatementRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *stmt;
@end
@interface KBRStartRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *username;
@end
@interface KBRFinishRequestParams : KBRRequestParams
@property NSInteger sessionID;
@end
@interface KBRPromptDeviceNameRequestParams : KBRRequestParams
@property NSInteger sessionID;
@end
@interface KBRSelectSignerRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSArray *devices;
@property BOOL hasPGP;
@end
@interface KBRDisplaySecretWordsRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *secret;
@property NSString *deviceNameExisting;
@property NSString *deviceNameToAdd;
@end
@interface KBRKexStatusRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *msg;
@property KBRKexStatusCode code;
@end
@interface KBRLogRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRLogLevel level;
@property KBRText *text;
@end
@interface KBRLoginWithPromptRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *username;
@end
@interface KBRLoginWithStoredSecretRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *username;
@end
@interface KBRLoginWithPassphraseRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *username;
@property NSString *passphrase;
@property BOOL storeSecret;
@end
@interface KBRClearStoredSecretRequestParams : KBRRequestParams
@property NSString *username;
@end
@interface KBRCancelLoginRequestParams : KBRRequestParams
@property NSInteger sessionID;
@end
@interface KBRGetEmailOrUsernameRequestParams : KBRRequestParams
@property NSInteger sessionID;
@end
@interface KBRPgpSignRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRStream *source;
@property KBRStream *sink;
@property KBRPgpSignOptions *opts;
@end
@interface KBRPgpPullRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSArray *userAsserts;
@end
@interface KBRPgpEncryptRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRStream *source;
@property KBRStream *sink;
@property KBRPgpEncryptOptions *opts;
@end
@interface KBRPgpDecryptRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRStream *source;
@property KBRStream *sink;
@property KBRPgpDecryptOptions *opts;
@end
@interface KBRPgpVerifyRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRStream *source;
@property KBRPgpVerifyOptions *opts;
@end
@interface KBRPgpImportRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSData *key;
@property BOOL pushSecret;
@end
@interface KBRPgpExportRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property BOOL secret;
@property NSString *query;
@end
@interface KBRPgpKeyGenRequestParams : KBRRequestParams
@property NSInteger primaryBits;
@property NSInteger subkeyBits;
@property KBRPgpCreateUids *createUids;
@property BOOL allowMulti;
@property BOOL doExport;
@end
@interface KBRPgpKeyGenDefaultRequestParams : KBRRequestParams
@property KBRPgpCreateUids *createUids;
@end
@interface KBRPgpSelectRequestParams : KBRRequestParams
@property NSString *query;
@property BOOL allowMulti;
@property BOOL skipImport;
@end
@interface KBRPgpUpdateRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property BOOL all;
@property NSArray *fingerprints;
@end
@interface KBRProveRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *service;
@property NSString *username;
@property BOOL force;
@end
@interface KBRPromptOverwriteRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *account;
@property KBRPromptOverwriteType typ;
@end
@interface KBRPromptUsernameRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *prompt;
@property KBRStatus *prevError;
@end
@interface KBROutputPrechecksRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRText *text;
@end
@interface KBRPreProofWarningRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRText *text;
@end
@interface KBROutputInstructionsRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRText *instructions;
@property NSString *proof;
@end
@interface KBROkToCheckRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *name;
@property NSInteger attempt;
@end
@interface KBRDisplayRecheckWarningRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRText *text;
@end
@interface KBRVerifySessionRequestParams : KBRRequestParams
@property NSString *session;
@end
@interface KBRRevokeKeyRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *id;
@end
@interface KBRRevokeDeviceRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *id;
@end
@interface KBRRevokeSigsRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSArray *ids;
@property NSArray *seqnos;
@end
@interface KBRGetSecretRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRSecretEntryArg *pinentry;
@property KBRSecretEntryArg *terminal;
@end
@interface KBRGetNewPassphraseRequestParams : KBRRequestParams
@property NSString *terminalPrompt;
@property NSString *pinentryDesc;
@property NSString *pinentryPrompt;
@property NSString *retryMessage;
@end
@interface KBRGetKeybasePassphraseRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *username;
@property NSString *retry;
@end
@interface KBRCheckUsernameAvailableRequestParams : KBRRequestParams
@property NSString *username;
@end
@interface KBRSignupRequestParams : KBRRequestParams
@property NSString *email;
@property NSString *inviteCode;
@property NSString *passphrase;
@property NSString *username;
@property NSString *deviceName;
@end
@interface KBRInviteRequestRequestParams : KBRRequestParams
@property NSString *email;
@property NSString *fullname;
@property NSString *notes;
@end
@interface KBRSigListRequestParams : KBRRequestParams
@property KBRSigListArgs *arg;
@end
@interface KBRSigListJSONRequestParams : KBRRequestParams
@property KBRSigListArgs *arg;
@end
@interface KBRCloseRequestParams : KBRRequestParams
@property KBRStream *s;
@end
@interface KBRReadRequestParams : KBRRequestParams
@property KBRStream *s;
@property NSInteger sz;
@end
@interface KBRWriteRequestParams : KBRRequestParams
@property KBRStream *s;
@property NSData *buf;
@end
@interface KBRTrackRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *theirName;
@property BOOL localOnly;
@property BOOL approveRemote;
@end
@interface KBRUntrackRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *theirName;
@end
@interface KBRPromptYesNoRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRText *text;
@property BOOL def;
@end
@interface KBRListTrackersRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property KBRUID *uid;
@end
@interface KBRListTrackersByNameRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *username;
@end
@interface KBRListTrackersSelfRequestParams : KBRRequestParams
@property NSInteger sessionID;
@end
@interface KBRLoadUncheckedUserSummariesRequestParams : KBRRequestParams
@property NSArray *uids;
@end
@interface KBRLoadUserRequestParams : KBRRequestParams
@property KBRUID *uid;
@property NSString *username;
@property BOOL self;
@end
@interface KBRListTrackingRequestParams : KBRRequestParams
@property NSString *filter;
@end
@interface KBRListTrackingJsonRequestParams : KBRRequestParams
@property NSString *filter;
@property BOOL verbose;
@end
@interface KBRSearchRequestParams : KBRRequestParams
@property NSInteger sessionID;
@property NSString *query;
@end