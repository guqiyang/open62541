/* This work is licensed under a Creative Commons CCZero 1.0 Universal License.
 * See http://creativecommons.org/publicdomain/zero/1.0/ for more information. 
 *
 *    Copyright 2016 (c) Fraunhofer IOSB (Author: Julius Pfrommer)
 */

#ifndef UA_NETWORK_TCP_H_
#define UA_NETWORK_TCP_H_

#include <open62541/client.h>
#include <open62541/plugin/log.h>
#include <open62541/server.h>

_UA_BEGIN_DECLS

/* Initializes a TCP network layer.
 *
 * @param config The connection config.
 * @param port The TCP port to listen to.
 * @param maxConnections Maximum number of TCP connections this network layer
 *                       instance is allowed to allocate. Set to 0 for unlimited
 *                       number of connections.
 * @param logger Pointer to a logger
 * @return Returns the network layer instance */
UA_ServerNetworkLayer UA_EXPORT
UA_ServerNetworkLayerTCP(UA_ConnectionConfig config, UA_UInt16 port,
                         UA_UInt16 maxConnections, UA_Logger *logger);

UA_Connection UA_EXPORT
UA_ClientConnectionTCP(UA_ConnectionConfig config, const UA_String endpointUrl,
                       UA_UInt32 timeout, UA_Logger *logger);

UA_StatusCode UA_EXPORT
UA_ClientConnectionTCP_poll(UA_Client *client, void *data);

UA_Connection UA_EXPORT
UA_ClientConnectionTCP_init(UA_ConnectionConfig config, const UA_String endpointUrl,
                            UA_UInt32 timeout, UA_Logger *logger);

_UA_END_DECLS

#endif /* UA_NETWORK_TCP_H_ */
