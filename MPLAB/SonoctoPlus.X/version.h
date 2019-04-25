/* 
 * File:   version.h
 * Author: dtiller
 *
 * Created on April 25, 2019, 7:05 PM
 */

#ifndef VERSION_H
#define	VERSION_H

#ifdef	__cplusplus
extern "C" {
#endif

#define MAX_VERSION 1
#define MIN_VERSION 0
#define VERSION ((MAX_VERSION << 8) + MIN_VERSION)


#ifdef	__cplusplus
}
#endif

#endif	/* VERSION_H */

